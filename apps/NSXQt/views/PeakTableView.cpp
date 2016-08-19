#include "PeakTableView.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <memory>

#include <QContextMenuEvent>
#include <QHeaderView>
#include <QInputDialog>
#include <QItemSelectionModel>
#include <QMouseEvent>
#include <QStandardItemModel>
#include <QtDebug>
#include <QMessageBox>

#include "IData.h"
#include "Peak3D.h"
#include "ProgressHandler.h"
#include "ProgressView.h"

PeakTableView::PeakTableView(QWidget *parent)
: QTableView(parent),
  _columnUp(-1,false),
  _normalized(false)
{
    // Make sure that the user can not edit the content of the table
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // Selection of a cell in the table select the whole line.
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    //
    setMinimumSize(800,400);
    setFocusPolicy(Qt::StrongFocus);

    // Set selection model
    setSelectionMode(QAbstractItemView::MultiSelection);

    // Signal sent when sorting by column
    QHeaderView* horizontal=this->horizontalHeader();
    connect(horizontal,SIGNAL(sectionClicked(int)),this,SLOT(sortByColumn(int)));

    // Signal sent when clicking on a row to plot peak
    QHeaderView* vertical=this->verticalHeader();
    connect(vertical, &QHeaderView::sectionClicked, [&](int index)
                                                 {
                                                  SX::Crystal::Peak3D& peak=_peaks[index].get();
                                                  emit plotPeak(&peak);
                                                 });

    connect(this,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(deselectPeak(QModelIndex)));
    // Hide the vertical Header
    this->verticalHeader()->hide();
}

void PeakTableView::setData(std::vector<std::shared_ptr<SX::Data::IData>> data)
{
    for (auto ptr : data)
    {
        // Add peaks present in this numor to the LatticeFinder
        for (auto& peak : ptr->getPeaks())
            _peaks.push_back(std::ref(*peak));
    }
    constructTable();
}

void PeakTableView::peakChanged(QModelIndex current, QModelIndex last)
{
    if (current.row()!=last.row())
    {
        SX::Crystal::Peak3D& peak=_peaks[current.row()].get();
        emit plotPeak(&peak);
    }
}

void PeakTableView::sortByColumn(int i)
{
    if (i>5 || i==2 ||  _peaks.size()==0)
        return;

    int& column=std::get<0>(_columnUp);
    bool& up=std::get<1>(_columnUp);
    // If column already sorted, swith direction
    if (i==column)
    {
        up=!up;
    }
    column=i;

    switch (i)
    {
    case 0:
    {
        sortByHKL(up);
        break;
    }
    case 1:
    {
        sortByIntensity(up);
        break;
    }
    case 3:
    {
        sortByTransmission(up);
        break;
    }
    case 4:
    {
        sortByNumor(up);
        break;
    }
    case 5:
    {
        sortBySelected(up);
        break;
    }
    }

    constructTable();
    QStandardItemModel* model=dynamic_cast<QStandardItemModel*>(this->model());
    QStandardItem* columni=model->horizontalHeaderItem(i);
    if (up)
        columni->setIcon(QIcon(":/resources/sortUpIcon.png"));
    else
        columni->setIcon(QIcon(":/resources/sortDownIcon.png"));
}

void PeakTableView::constructTable()
{
    // icons for selected and deselected peaks
    QIcon selectedIcon(":/resources/peakSelectedIcon.png");
    QIcon deselectedIcon(":/resources/peakDeselectedIcon.png");

    // set up progress handler and view
    std::shared_ptr<SX::Utils::ProgressHandler> progressHandler(new SX::Utils::ProgressHandler);
    ProgressView progressView(this);

    progressView.watch(progressHandler);
    progressHandler->setStatus("Creating peak tables..");
    progressHandler->setProgress(0);

    // Create table
    QStandardItemModel* model=new QStandardItemModel(_peaks.size(),6,this);
    model->setHorizontalHeaderItem(0,new QStandardItem("h k l"));
    model->setHorizontalHeaderItem(1,new QStandardItem("I"));
    model->setHorizontalHeaderItem(2,new QStandardItem(QString((QChar) 0x03C3)+"I"));
    model->setHorizontalHeaderItem(3,new QStandardItem("Transmission"));
    model->setHorizontalHeaderItem(4,new QStandardItem("Numor"));
    model->setHorizontalHeaderItem(5,new QStandardItem("Selected"));


    int i = 0;

    // Setup content of the table
    for (SX::Crystal::Peak3D& peak : _peaks)
    {
        const Eigen::RowVector3d& hkl = peak.getMillerIndices();

        QStandardItem* col0 = new QStandardItem(QString::number(hkl[0],'f',2)
                + "  " + QString::number(hkl[1],'f',2)
                + "  " + QString::number(hkl[2],'f',2));

        double l = peak.getLorentzFactor();
        double t = peak.getTransmission();

        QStandardItem* col1 = new QStandardItem(QString::number(peak.getScaledIntensity()/l/t,'f',2));
        QStandardItem* col2 = new QStandardItem(QString::number(peak.getScaledSigma()/l/t,'f',2));
        QStandardItem* col3 = new QStandardItem(QString::number(t,'f',2));
        QStandardItem* col4 = new QStandardItem(QString::number(peak.getData()->getMetadata()->getKey<int>("Numor")));
        QStandardItem* col5;

        if (peak.isSelected())
            col5= new QStandardItem(selectedIcon,"");
        else
            col5= new QStandardItem(deselectedIcon, "");

        model->setItem(i,0,col0);
        model->setItem(i,1,col1);
        model->setItem(i,2,col2);
        model->setItem(i,3,col3);
        model->setItem(i,4,col4);
        model->setItem(i++,5,col5);

        progressHandler->setProgress(i * 100.0 / _peaks.size() );
    }
    setModel(model);

    this->setColumnWidth(0,150);

    // Signal sent when the user navigates the table (e.g. up down arrow )
    connect(this->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),this,SLOT(peakChanged(QModelIndex,QModelIndex)));
}

void PeakTableView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
        return;

    QTableView::mousePressEvent(event);
}

void PeakTableView::keyPressEvent(QKeyEvent *event)
{
    QModelIndexList selected=selectedIndexes();
    if (selected.isEmpty())
        return;

    // take last element
    QModelIndex last=selected.last();
    unsigned int index=last.row();
    if (event->key() ==Qt::Key_Up) // Deal with up and down arrow
    {
       --index;
    }
    else if (event->key() ==Qt::Key_Down)
    {
        ++index;
    }
    else if (event->key()==Qt::Key_Space) // Change status of peak from unselected to selected by using spacebar
    {
        auto& peak=_peaks[index].get();
        bool newstatus=!peak.isSelected();
        peak.setSelected(newstatus);
        QStandardItemModel* model=dynamic_cast<QStandardItemModel*>(this->model());
        if (newstatus)
            model->setItem(index,5,new QStandardItem(QIcon(":/resources/peakSelectedIcon.png"),""));
        else
            model->setItem(index,5,new QStandardItem(QIcon(":/resources/peakDeselectedIcon.png"),""));
        emit plotPeak(&peak);
    }

    if (index>_peaks.size()-1)
        return;
    if (!isRowHidden(index))
    {
        clearSelection();
        selectRow(index);
        SX::Crystal::Peak3D& peak=_peaks[index].get();
        emit plotPeak(&peak);
    }
}

void PeakTableView::contextMenuEvent(QContextMenuEvent* event)
{
    // Show all peaks as selected when contet menu is requested
    QMenu* menu=new QMenu(this);
    //
    QAction* sortbyEquivalence=new QAction("Sort by equivalences",menu);
    menu->addAction(sortbyEquivalence);
    connect(sortbyEquivalence,SIGNAL(triggered()),this,SLOT(sortEquivalents()));

    QAction* normalize=new QAction("Normalize to monitor",menu);
    menu->addSeparator();
    menu->addAction(normalize);
    QMenu* writeMenu=menu->addMenu("Write");
    QAction* writeFullProf=new QAction("FullProf file",writeMenu);
    QAction* writeShelX=new QAction("SHELX file",writeMenu);
    writeMenu->addAction(writeFullProf);
    writeMenu->addAction(writeShelX);

    // Menu to plot against metadata
    QModelIndexList indexList = selectionModel()->selectedIndexes();
    if (indexList.size()) //at least on peak
    {
        QMenu* plotasmenu=menu->addMenu("Plot as");
        SX::Data::MetaData* met=_peaks[indexList[0].row()].get().getData()->getMetadata();
        const std::set<std::string>& keys=met->getAllKeys();
        for (const auto& key : keys)
        {
             try
             {
                met->getKey<double>(key); //Ensure metadata is a Numeric tyoe
             }catch(std::exception& e)
            {
                continue;
            }
             QAction* newparam=new QAction(QString::fromStdString(key),plotasmenu);
             connect(newparam,&QAction::triggered,this,[&](){plotAs(key);}); // New way to connect slot using C++ 2011 lambda sicne Qt 5
             plotasmenu->addAction(newparam);
        }
    }

    // Connections
    connect(normalize,SIGNAL(triggered()),this,SLOT(normalizeToMonitor()));
    connect(writeFullProf,SIGNAL(triggered()),this,SLOT(writeFullProf()));
    connect(writeShelX,SIGNAL(triggered()),this,SLOT(writeShelX()));
    menu->popup(event->globalPos());

}

void PeakTableView::normalizeToMonitor()
{
    bool ok;
    double factor = QInputDialog::getDouble(this,"Enter normalization factor","",1,1,100000000,1,&ok);
    if (ok)
    {
        for (SX::Crystal::Peak3D& peak : _peaks)
            peak.setScale(factor/peak.getData()->getMetadata()->getKey<double>("monitor"));
        // Keep track of the last selected index before rebuilding the table
        QModelIndex index=currentIndex();
        constructTable();
        _normalized=true;
        selectRow(index.row());
        // If no row selected do nothing else.
        if (!index.isValid())
            return;
        SX::Crystal::Peak3D& peak=_peaks[index.row()].get();
        emit plotPeak(&peak);
    }
}

void PeakTableView::writeFullProf()
{
    if (!_peaks.size())
        qCritical()<<"No peaks in the table";

    if (!checkBeforeWritting())
        return;

    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save FullProf file"),
                                                    QString::fromStdString(getPeaksRange()+".int"),
                                                    tr("FullProf Files (*.int)"),
                                                    nullptr,
                                                    QFileDialog::DontUseNativeDialog);
    if (filename.isEmpty())
        return;

    std::fstream file(filename.toStdString(),std::ios::out);

    if (!file.is_open())
    {
        qCritical()<<"Error writing to this file, please check write permisions";
        return;
    }

    file << "TITLE File written by ...\n";
    file << "(3i4,2F14.4,i5,4f8.2)\n";
    double wave=_peaks[0].get().getData()->getMetadata()->getKey<double>("wavelength");
    file << std::fixed << std::setw(8) << std::setprecision(3) << wave << " 0 0" << std::endl;
    for (const SX::Crystal::Peak3D& peak : _peaks)
    {
        if (peak.isSelected())
        {
            const Eigen::RowVector3d& hkl=peak.getMillerIndices();

            file << std::setprecision(0);
            file << std::setw(4);
            file << hkl[0] << std::setw(4) <<  hkl[1] << std::setw(4) << hkl[2];
            double l=peak.getLorentzFactor();
            double t=peak.getTransmission();
            file << std::fixed << std::setw(14) << std::setprecision(4) << peak.getScaledIntensity()/l/t;
            file << std::fixed << std::setw(14) << std::setprecision(4) << peak.getScaledSigma()/l/t;
            file << std::setprecision(0) << std::setw(5) << 1  << std::endl;
        }
    }
    if (file.is_open())
        file.close();
}


void PeakTableView::writeShelX()
{
    if (!_peaks.size())
    {
        qCritical()<<"No peaks in the table";
        return;
    }

    if (!checkBeforeWritting())
        return;

    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save ShelX file"),
                                                    QString::fromStdString(getPeaksRange()+".hkl"),
                                                    tr("ShelX Files (*.hkl)"),
                                                    nullptr,
                                                    QFileDialog::DontUseNativeDialog);
    if (filename.isEmpty())
        return;

    std::fstream file(filename.toStdString().c_str(),std::ios::out);
    if (!file.is_open())
    {
        qCritical()<<"Error writing to this file, please check write permisions";
        return;
    }

    for (const SX::Crystal::Peak3D& peak : _peaks)
    {
        if (peak.isSelected())
        {
            const Eigen::RowVector3d& hkl=peak.getMillerIndices();

            file << std::fixed;
            file << std::setprecision(0);
            file << std::setw(4);
            file << hkl[0];

            file << std::fixed;
            file << std::setprecision(0);
            file << std::setw(4);
            file <<  hkl[1];

            file << std::fixed;
            file << std::setprecision(0);
            file << std::setw(4);
            file << hkl[2];

            double l=peak.getLorentzFactor();
            double t=peak.getTransmission();
            file << std::fixed << std::setw(8) << std::setprecision(2) << peak.getScaledIntensity()/l/t;
            file << std::fixed << std::setw(8) << std::setprecision(2) << peak.getScaledSigma()/l/t <<std::endl;
            }
    }
    if (file.is_open())
        file.close();
}

void PeakTableView::sortByHKL(bool up)
{
    if (up)
        std::sort(_peaks.begin(),_peaks.end(),
              [&](const SX::Crystal::Peak3D& p1, const SX::Crystal::Peak3D& p2)
              {
                return (p2<p1);
              }
              );
    else
        std::sort(_peaks.begin(),_peaks.end());
}

void PeakTableView::sortBySelected(bool up)
{
    if (up)
        std::sort(_peaks.begin(),_peaks.end(),
              [&](const SX::Crystal::Peak3D& p1, const SX::Crystal::Peak3D& p2)
              {
                return (p2.isSelected()<p1.isSelected());
              }
              );
    else
        std::sort(_peaks.begin(),_peaks.end(),
              [&](const SX::Crystal::Peak3D& p1, const SX::Crystal::Peak3D& p2)
              {
                return (p2.isSelected()>p1.isSelected());
              }
              );
}

void PeakTableView::sortByTransmission(bool up)
{
    if (up)
        std::sort(_peaks.begin(),_peaks.end(),
              [&](const SX::Crystal::Peak3D& p1, const SX::Crystal::Peak3D& p2)
                {
                    return (p1.getTransmission()>p2.getTransmission());
                });
    else
        std::sort(_peaks.begin(),_peaks.end(),
                  [&](const SX::Crystal::Peak3D& p1, const SX::Crystal::Peak3D& p2)
                    {
                        return (p1.getTransmission()<p2.getTransmission());
                    });
}

void PeakTableView::sortByIntensity(bool up)
{
    if (up)
        std::sort(_peaks.begin(),_peaks.end(),
              [&](const SX::Crystal::Peak3D& p1, const SX::Crystal::Peak3D& p2)
                {
                    return ((p1.getScaledIntensity()/p1.getLorentzFactor()/p1.getTransmission())>(p2.getScaledIntensity()/p2.getLorentzFactor()/p2.getTransmission()));
                });
    else
        std::sort(_peaks.begin(),_peaks.end(),
                  [&](const SX::Crystal::Peak3D& p1, const SX::Crystal::Peak3D& p2)
                    {
            return ((p1.getScaledIntensity()/p1.getLorentzFactor()/p1.getTransmission())<(p2.getScaledIntensity()/p2.getLorentzFactor()/p2.getTransmission()));
                    });
}

void PeakTableView::sortByNumor(bool up)
{
    if (up)
        std::sort(_peaks.begin(),_peaks.end(),
              [&](const SX::Crystal::Peak3D& p1, const SX::Crystal::Peak3D& p2)
                {
                    int numor1=p1.getData()->getMetadata()->getKey<int>("Numor");
                    int numor2=p2.getData()->getMetadata()->getKey<int>("Numor");
                    return (numor1>numor2);
                });
    else
        std::sort(_peaks.begin(),_peaks.end(),
              [&](const SX::Crystal::Peak3D& p1, const SX::Crystal::Peak3D& p2)
                {
                    int numor1=p1.getData()->getMetadata()->getKey<int>("Numor");
                    int numor2=p2.getData()->getMetadata()->getKey<int>("Numor");
                    return (numor1<numor2);
                });
}

void PeakTableView::deselectPeak(QModelIndex index)
{
    auto& peak=_peaks[index.row()];
    peak.get().setSelected(!peak.get().isSelected());
    constructTable();
}

void PeakTableView::plotAs(const std::string& key)
{
     QModelIndexList indexList = selectionModel()->selectedIndexes();
     if (!indexList.size())
         return;

    int nPoints=indexList.size();

    QVector<double> x(nPoints);
    QVector<double> y(nPoints);
    QVector<double> e(nPoints);

    for (int i=0;i<nPoints;++i)
    {
        SX::Crystal::Peak3D p=_peaks[indexList[i].row()].get();
        x[i]=p.getData()->getMetadata()->getKey<double>(key);
        y[i]=p.getScaledIntensity();
        e[i]=p.getScaledSigma();
    }

    emit plotData(x,y,e);
}

std::string PeakTableView::getPeaksRange() const
{
    std::set<std::string> temp;

    for (auto p : _peaks)
        temp.insert(std::to_string(p.get().getData()->getMetadata()->getKey<int>("Numor")));

    std::string range(*(temp.begin()));

    std::string last=*(temp.rbegin());

    if (range.compare(last)!=0)
        range += "_"+last;

    return range;
}

void PeakTableView::sortEquivalents()
{
    qDebug() << "Sorting";
    auto ptrcell=_peaks[0].get().getUnitCell();
    std::sort(_peaks.begin(),
              _peaks.end(),
              [&](const SX::Crystal::Peak3D& p1, const SX::Crystal::Peak3D& p2)
                {
                    Eigen::Vector3d hkl1=p1.getMillerIndices();
                    Eigen::Vector3d hkl2=p2.getMillerIndices();
                    if (ptrcell->isEquivalent(hkl1[0],hkl1[1],hkl1[2],hkl2[0],hkl2[1],hkl2[2]))
                        return true;
                    else
                        return false;
                }
              );
}

bool PeakTableView::checkBeforeWritting()
{
    if (!_normalized)
    {
        int reply=QMessageBox::question(this,"Writing data","No normalisation (time/monitor) has been found. Are you sure you want to export",(QMessageBox::Yes | QMessageBox::Abort));
        if (reply==QMessageBox::Abort)
            return false;
    }
    return true;
}

void PeakTableView::showPeaksMatchingText(QString text)
{
    QStringList list=text.split(" ");
    int nterms=list.size();

    if (nterms<3) // Don't search if h,k,l not complete
    {
        unsigned int row=0;
        for (row=0;row<_peaks.size();row++)
        {
            setRowHidden(row,false);
        }
        return;
    }

    bool okh=false,okk=false,okl=false;
    double h=list[0].toDouble(&okh);
    double k=list[1].toDouble(&okk);
    double l=list[2].toDouble(&okl);

    if (!(okh && okk && okl)) // If problem parsing h k l into double
    {
        unsigned int row=0;
        for (row=0;row<_peaks.size();row++)
        {
            setRowHidden(row,false);
        }
        return;
    }

    unsigned int row=0;
    for (row=0;row<_peaks.size();row++)
    {
        auto& p=_peaks[row].get();
        Eigen::Vector3d hkl=p.getMillerIndices();
        if (std::fabs(hkl[0]-h)>1e-2 || std::fabs(hkl[1]-k)>1e-2 || std::fabs(hkl[2]-l)>1e-2)
        {
            setRowHidden(row,true);
        }
        else
            setRowHidden(row,false);
    }
}


