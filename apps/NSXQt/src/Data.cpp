#include "Data.h"
#include "ILLAsciiDataReader.h"
#include <algorithm>
#include <iostream>
#include <QProgressBar>
#include <string>
#include "CylindricalDetector.h"
#include "Units.h"
#include "Gonio.h"

using namespace SX::Units;

void D19Mapping(double x, double y, double& newx, double& newy)
{
    newx = 640 - x;
    newy = 256 - y;
}

Data::Data():SX::Geometry::IData(SX::Data::ILLAsciiDataReader::create()),_inmemory(false),_maxCount(0),_detector(nullptr),_sample(nullptr)
{

}
Data::~Data()
{
    if (_detector)
        delete _detector;
    if (_sample)
        delete _sample;
}

Data::Data(const Data& rhs):SX::Geometry::IData(SX::Data::ILLAsciiDataReader::create())
{
    _inmemory=rhs._inmemory;
    _maxCount=rhs._maxCount;
    _detector=rhs._detector;
    _sample=rhs._sample;

}

void Data::fromFile(const std::string& filename)
{
    _mm->open(filename.c_str());
    _nblocks=_mm->nFrames();
    _sum.resize(_nblocks);
    _currentFrame=std::move(_mm->getFrame(0));
    _sum[0]=std::accumulate(_currentFrame.begin(),_currentFrame.end(),0,std::plus<int>());

    SX::Data::MetaData* meta=_mm->getMetaData();
    std::string instrName = meta->getKey<std::string>("Instrument");

    if (instrName.compare("D19")==0)
    {
        _detector = new SX::Instrument::CylindricalDetector();

        _detector->setDistance(764*SX::Units::mm);
        _detector->setWidthAngle(120.0*deg);
        _detector->setHeight(40.0*cm);
        _detector->setNPixels(640,256);

        _detector->setDataMapping(&D19Mapping);

        _chi=meta->getKey<double>("chi")*deg;
        _phi=meta->getKey<double>("phi")*deg;

        double scanstart=meta->getKey<double>("scanstart")*deg;
        double scanstep=meta->getKey<double>("scanstep")*deg;
        int npdone=meta->getKey<int>("npdone");

        _omegas.resize(npdone);
        int i=0;
        std::generate(_omegas.begin(),_omegas.end(),[&i,scanstart,scanstep](){return scanstart+(i++)*scanstep;});

        _wavelength = meta->getKey<double>("wavelength");

        // Attach a gonio to the detector
        std::shared_ptr<SX::Instrument::Gonio> g(new SX::Instrument::Gonio("gamma-arm"));
        g->addRotation("gamma",Eigen::Vector3d(0,0,1),SX::Instrument::RotAxis::CW);
        _detector->setGonio(g);
        double gamma = meta->getKey<double>("2theta(gamma)")*deg;
        g->setCurrentValues({gamma});

        //Sample gonio
        _sample= new SX::Instrument::Gonio("Busing Levy convention");
        _sample->addRotation("omega",Vector3d(0,0,1),SX::Instrument::RotAxis::CW);
        _sample->addRotation("chi",Vector3d(0,1,0),SX::Instrument::RotAxis::CCW);
        _sample->addRotation("phi",Vector3d(0,0,1),SX::Instrument::RotAxis::CW);
    }

}

void Data::readBlock(int i)
{
    if (!_inmemory)
    {
        _currentFrame=std::move(_mm->getFrame(i));
        _sum[i]=std::accumulate(_currentFrame.begin(),_currentFrame.end(),0,std::plus<int>());
    }
    else
    {
        _currentFrame=_data[i];
    }
    auto it=std::max_element(_currentFrame.begin(),_currentFrame.end());
    _maxCurrentFrame=(*it);
}
void Data::readInMemory()
{
    if (!_inmemory)
    {
        _data.resize(_nblocks);

        int count=0;


#pragma omp parallel for shared(count)
        for (int i=0;i<_nblocks;++i)
        {
            _data[i].reserve(640*256);
            _data[i]=std::move(_mm->getFrame(i));
            _sum[i]=std::accumulate(_data[i].begin(),_data[i].end(),0,std::plus<int>());
            auto it=std::max_element(_data[i].begin(),_data[i].end(),std::less<int>());
            if ((*it)>count)
                count=(*it);
        }
        _maxCount=count;
        _inmemory=true;
    }
}
// Release the Data from memory
void Data::releaseMemory()
{
    if (!_inmemory)
        return;
    for (auto i=0;i<_nblocks;++i)
    {
        _data[i].clear();
    }
    _data.clear();
    _sum.clear();
    _inmemory=false;
    _maxCount=0;
}

void Data::getCountsHistogram(std::vector<int>& histo)
{
    if (!_inmemory)
        readInMemory();
    //
    histo.resize(_maxCount);

    for (auto i=0;i<_nblocks;++i)
    {
        std::vector<int>& d=_data[i];
        for (unsigned int j=0;j<d.size();++j)
        {
            histo[d[j]]++;
        }
    }
}

bool Data::has3DEllipsoid() const
{
    return (_peaks.size()!=0);
}

void Data::clear3DEllipsoids()
{
    _peaks.clear();
}

int Data::dataAt(int x, int y, int z)
{
    if (z<0 || z>=_nblocks || y<0 || y>=256 || x<0 || x>=640)
        return 0;
    return (_data[z])[x*256+y];
}

int Data::getBackgroundLevel()
{
    std::vector<int> v;
    getCountsHistogram(v);
    auto max=std::max_element(v.begin(),v.end());
    int background_level=std::distance(v.begin(),max)+1;
    return background_level;
}