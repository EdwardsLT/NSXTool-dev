/*
 * nsxtool : Neutron Single Crystal analysis toolkit
    ------------------------------------------------------------------------------------------
    Copyright (C)
    2012- Laurent C. Chapon Institut Laue-Langevin
	BP 156
	6, rue Jules Horowitz
	38042 Grenoble Cedex 9
	France
	chapon[at]ill.fr
    pellegrini[at]ill.fr

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef NSXTOOL_SIMPLEPEAK_H_
#define NSXTOOL_SIMPLEPEAK_H_

#include <map>
#include <memory>

#include <Eigen/Dense>

#include "UnitCell.h"
#include "IShape.h"

namespace SX
{

namespace Data
{
	class IData;
}

namespace Instrument
{
	class Diffractometer;
	class ComponentState;
	class DetectorEvent;
	class Sample;
	class Detector;
	class Source;
}

namespace Crystal
{

class Peak3D
{
public:

    Peak3D(std::shared_ptr<SX::Data::IData> data=std::shared_ptr<SX::Data::IData>());
	Peak3D(const Peak3D& other);
	Peak3D& operator=(const Peak3D& other);
	~Peak3D();
	//! Attach the data
    void linkData(std::shared_ptr<SX::Data::IData> data);

	//! Detach the data
	void unlinkData();

	//! Set the Peak region. Peak shaped is owned after setting
	void setPeakShape(SX::Geometry::IShape<double,3>* peak);

	//! set the background region. Bkg region is owned after setting
	void setBackgroundShape(SX::Geometry::IShape<double,3>* background);

	//! Set the Miller indices of the peak (double to allow integration of incommensurate peaks)
	void setMillerIndices(double h, double k, double l);

	//! Get the Miller indices of the peak (double to allow integration of incommensurate peaks)
	const Eigen::RowVector3d& getMillerIndices() const;

	//! Get kf vector in the frame of reference of the diffractometer
	Eigen::RowVector3d getKf() const;

	//! Get q vector in the frame of reference of the diffractometer
	Eigen::RowVector3d getQ() const;

	void getGammaNu(double& gamma,double& nu) const;

	//! Run the integration of the peak; iterate over the data
	void integrate();

	//!
    const std::shared_ptr<SX::Data::IData> getData() const { return _data;}

    std::shared_ptr<SX::Data::IData> getData() { return _data;}

	//! Get the projection of total data in the bounding box.
	Eigen::VectorXd getProjection() const;
	Eigen::VectorXd getPeakProjection() const;
	Eigen::VectorXd getBkgProjection() const;
	Eigen::VectorXd getProjectionSigma() const;
	Eigen::VectorXd getPeakProjectionSigma() const;
	Eigen::VectorXd getBkgProjectionSigma() const;
	const SX::Geometry::IShape<double,3>* getPeak() const { return _peak;}
	const SX::Geometry::IShape<double,3>* getBackground() const {return _bkg;}
	//! Return the scaled intensity of the peak.
   	double getScaledIntensity() const;
	//! Return the raw intensity of the peak.
   	double getRawIntensity() const;
	//! Returns the error on the raw intensity.
   	double getRawSigma() const;
	//! Returns the error on the scaled intensity.
   	double getScaledSigma() const;
   	//!
   	double getIOverSigmaI() const;
   	//! Return the lorentz factor of the peak.
   	double getLorentzFactor() const;
    std::shared_ptr<SX::Instrument::ComponentState> getSampleState();
    std::shared_ptr<SX::Instrument::DetectorEvent> getDetectorEvent();
   	//! Return the scaling factor.
   	double getScale() const;
   	//! Rescale the current scaling factor by scale.
   	void rescale(double factor);
   	//! Set the scaling factor.
   	void setScale(double factor);
   	//!
    void setSampleState(std::shared_ptr<SX::Instrument::ComponentState> gstate);
   	//!
    void setDetectorEvent(std::shared_ptr<SX::Instrument::DetectorEvent> event);
   	//!
    void setSource(std::shared_ptr<SX::Instrument::Source> source);
   	bool setUnitCell(std::shared_ptr<SX::Crystal::UnitCell> basis);
   	std::shared_ptr<SX::Crystal::UnitCell> getUnitCell() const;
	bool hasIntegerHKL(const SX::Crystal::UnitCell& basis);
	friend bool operator<(const Peak3D& p1, const Peak3D& p2);
	void setSelected(bool);
	bool isSelected() const;
	void setMasked(bool masked);
	bool isMasked() const;
	void setTransmission(double transmission);
	double getTransmission() const;

    // testing: new implementation of integration
    void framewiseIntegrateBegin();
    void framewiseIntegrateStep(Eigen::MatrixXi& frame, unsigned int idx);
    void framewiseIntegrateEnd();

private:
	//! Pointer to the data containing the peak
    std::shared_ptr<SX::Data::IData> _data;
	//! Miller indices of the peak
	Eigen::RowVector3d _hkl;
	//! Shape describing the Peak zone
	SX::Geometry::IShape<double,3>* _peak;
	//! Shape describing the background zone (must fully contain peak)
	SX::Geometry::IShape<double,3>* _bkg;
	//!
	Eigen::VectorXd _projection;
	Eigen::VectorXd _projectionPeak;
	Eigen::VectorXd _projectionBkg;
	//!
	std::shared_ptr<SX::Crystal::UnitCell> _basis;
	//! Pointer to the state of the Sample Component
    std::shared_ptr<SX::Instrument::ComponentState> _sampleState;
	//! Pointer to a Detector Event state
    std::shared_ptr<SX::Instrument::DetectorEvent> _event;
	//!
    std::shared_ptr<SX::Instrument::Source> _source;
	double _counts, _countsSigma;
	double _scale;
	bool _selected;
	bool _masked;
	double _transmission;

    
    struct IntegrationState {
        Eigen::Vector3d lower;
        Eigen::Vector3d upper;

        unsigned int data_start;
        unsigned int data_end;

        unsigned int start_x;
        unsigned int end_x;

        unsigned int start_y;
        unsigned int end_y;

        Eigen::Vector4d point1;

        int dx;
        int dy;
    };

    IntegrationState _state;


};


}
}
#endif /* NSXTOOL_SIMPLEPEAK_H_ */