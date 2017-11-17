%module "pynsx"

%include "pynsx_doc.i"

%include "warnings.i"

%include "typemaps.i"
%include "cpointer.i"

%include "std_shared_ptr.i"
%include "std_string.i"
%include "std_vector.i"
%include "std_set.i"
%include "std_pair.i"

%template(vector_1d)  std::vector<double>;
%template(vector_2d)  std::vector<std::vector<double>>;
%template(vector_1i) std::vector<int>;
%template(vector_2i) std::vector<std::vector<int>>;
%template(vector_string) std::vector<std::string>;

%shared_ptr(nsx::Peak3D)
%shared_ptr(nsx::Material)
%shared_ptr(nsx::Diffractometer)
%shared_ptr(nsx::ConvolutionKernel)
%shared_ptr(nsx::DeltaKernel)
%shared_ptr(nsx::AnnularKernel)
%shared_ptr(nsx::Convolver)
%shared_ptr(nsx::DataSet)
%shared_ptr(nsx::Source)
%shared_ptr(nsx::Sample)
%shared_ptr(nsx::IDataReader)
%shared_ptr(nsx::HDF5DataReader)
%shared_ptr(nsx::ILLDataReader)
%shared_ptr(nsx::I16DataReader)
%shared_ptr(nsx::RawDataReader)
%shared_ptr(nsx::TiffDataReader)
%shared_ptr(nsx::Experiment)
%shared_ptr(nsx::ProgressHandler)
%shared_ptr(nsx::Basis)
%shared_ptr(nsx::UnitCell)
%shared_ptr(nsx::Component)
%shared_ptr(nsx::Detector)
%shared_ptr(nsx::MonoDetector)
%shared_ptr(nsx::FlatDetector)
%shared_ptr(nsx::CylindricalDetector)
%shared_ptr(nsx::Gonio)

%{
#pragma GCC diagnostic ignored "-Wpedantic"
#define SWIG_FILE_WITH_INIT

#include <Python.h>
#include <numpy/arrayobject.h>

#include <memory>

#include <Eigen/Core>
#include <Eigen/Geometry>

using Eigen::RowVector2d;
using Eigen::Vector2d;
using Eigen::RowVector3d;
using Eigen::Vector3d;
using Eigen::RowVector3i;
using Eigen::Vector3i;
using Eigen::Matrix3d;
using Eigen::Matrix;
using Eigen::Quaterniond;

#include "Material.h"
#include "IsotopeDatabaseManager.h"

#include "ErfInv.h"
#include "Gaussian.h"
#include "GCD.h"
#include "Interpolator.h"
#include "Lorentzian.h"
#include "FitParameters.h"
#include "Minimizer.h"

#include "Round.h"
#include "RNG.h"
#include "Profile3d.h"

#include "EigenToVector.h"
#include "System.h"
#include "CSV.h"
#include "Enums.h"
#include "Units.h"

#include "DoubleToFraction.h"
#include "Timer.h"
#include "Path.h"
#include "Maybe.h"

#include "LMFunctor.h"
#include "RandomMatrix.h"
#include "Parser.h"
#include "YAMLType.h"
#include "MatrixParser.h"
#include "ProgressHandler.h"

#include "PeakPredictor.h"
#include "UBSolution.h"
#include "UBMinimizer.h"
#include "Refiner.h"
#include "AutoIndexer.h"
#include "Profile.h"
#include "Intensity.h"
#include "PeakIntegrator.h"
#include "UnitCell.h"
#include "ResolutionShell.h"
#include "RFactor.h"
#include "CC.h"
#include "Peak3D.h"

#include "PeakRecord.h"
#include "Mosaic.h"
#include "FFTIndexing.h"

#include "MergedPeak.h"
#include "Peak2D.h"
#include "SpaceGroup.h"
#include "NiggliReduction.h"
#include "GruberReduction.h"
#include "SymOp.h"
#include "Vertex.h"
#include "Triangle.h"

#include "Basis.h"
#include "Ellipsoid.h"
#include "Face.h"
#include "MCAbsorption.h"
#include "ConvexHull.h"
#include "BrillouinZone.h"

#include "BlobFinder.h"

#include "AABB.h"
#include "Edge.h"
#include "Blob3D.h"
#include "IntegrationRegion.h"

#include "DirectVector.h"
#include "ReciprocalVector.h"

#include "XDS.h"
#include "DataSet.h"
#include "MetaData.h"
#include "ILLDataReader.h"
#include "IDataReader.h"
#include "HDF5DataReader.h"
#include "I16DataReader.h"
#include "BasicFrameIterator.h"
#include "RawDataReader.h"
#include "ThreadedFrameIterator.h"
#include "IFrameIterator.h"
#include "TiffDataReader.h"
#include "BloscFilter.h"
#include "PeakFinder.h"
#include "DataReaderFactory.h"
#include "Detector.h"
#include "DetectorFactory.h"
#include "TransAxis.h"
#include "Sample.h"
#include "ComponentState.h"
#include "FlatDetector.h"
#include "Source.h"
#include "InstrumentState.h"
#include "MultiDetector.h"
#include "Monochromator.h"
#include "MonoDetector.h"
#include "Diffractometer.h"
#include "CylindricalDetector.h"
#include "Gonio.h"
#include "DetectorEvent.h"
#include "Axis.h"
#include "Experiment.h"

#include "Component.h"
#include "AxisFactory.h"
#include "RotAxis.h"
#include "PhysicalUnit.h"
#include "ConstantKernel.h"
#include "KernelFactory.h"
#include "Convolver.h"

#include "DeltaKernel.h"
#include "AnnularKernel.h"
#include "ConvolutionKernel.h"

#include "Composite.h"

#include "Memento.h"
#include "Singleton.h"
#include "Factory.h"

#include "Enums.h"

#include "Axis.h"
#include "RotAxis.h"
#include "TransAxis.h"
#include "Gonio.h"
  
#include "ComponentState.h"
#include "Component.h"
#include "Monochromator.h"

#include "Detector.h"
#include "MonoDetector.h"
#include "CylindricalDetector.h"
#include "FlatDetector.h"
 
#include "Source.h"

#include "Material.h"

using sptrMaterial = std::shared_ptr<nsx::Material>;
 
#include "Sample.h"

#include "Basis.h"
#include "AABB.h"
#include "Ellipsoid.h"
#include "Blob3D.h"

#include "FFTIndexing.h"
#include "Peak3D.h"
#include "SpaceGroup.h"
#include "UnitCell.h"
#include "GruberReduction.h"
#include "PeakIntegrator.h"
#include "Profile.h"
#include "Intensity.h"

using sptrUnitCell = std::shared_ptr<nsx::UnitCell>;

#include "Diffractometer.h"

#include "Singleton.h"

#include "MetaData.h"
#include "IDataReader.h"
#include "DataReaderFactory.h"
#include "ILLDataReader.h"
#include "HDF5DataReader.h"
#include "DataSet.h"
#include "PeakFinder.h"
#include "MergedData.h"

#include "CC.h"
#include "RFactor.h"

using namespace nsx;

%}

%include "numpy.i"
%include "eigen.i"

%init %{
    import_array();
%}

%include <typemaps.i>
%include <std_vector.i>

// eigen.i is found in ../swig/ and contains specific definitions to convert
// Eigen matrices into Numpy arrays.
%include <eigen.i>

%template(vectorMatrixXd) std::vector<Eigen::MatrixXd>;
%template(vectorVectorXd) std::vector<Eigen::VectorXd>;
%template(vectorVector3d) std::vector<Eigen::Vector3d>;
%template(vectorRowVector3d) std::vector<Eigen::RowVector3d>;

// Since Eigen uses templates, we have to declare exactly which types we'd
// like to generate mappings for
//%eigen_typemaps(Eigen::Vector3i)
%eigen_typemaps(Eigen::Vector3d)
%eigen_typemaps(Eigen::Vector4d)
%eigen_typemaps(Eigen::RowVector3i)
%eigen_typemaps(Eigen::RowVector3d)
%eigen_typemaps(Eigen::RowVector4d)
%eigen_typemaps(Eigen::Matrix3d)
%eigen_typemaps(Eigen::VectorXd)
%eigen_typemaps(Eigen::MatrixXd)
%eigen_typemaps(Eigen::MatrixXi)
%eigen_typemaps(Eigen::ArrayXd)
%eigen_typemaps(Eigen::ArrayXXd)
// Even though Eigen::MatrixXd is just a typedef for Eigen::Matrix<double,
// Eigen::Dynamic, Eigen::Dynamic>, our templatedInverse function doesn't
// compile correctly unless we also declare typemaps for Eigen::Matrix<double,
// Eigen::Dynamic, Eigen::Dynamic>. Not totally sure why that is.
%eigen_typemaps(Eigen::Matrix<double, 3, 1>)
%eigen_typemaps(Eigen::Matrix<double, 1, 3>)
%eigen_typemaps(Eigen::Matrix<double, 4, 1>)
%eigen_typemaps(Eigen::Matrix<double, 1, 4>)
%eigen_typemaps(Eigen::Matrix<int, 3, 1>)
%eigen_typemaps(Eigen::Matrix<int, 1, 3>)
%eigen_typemaps(Eigen::Matrix<double, 3, 3>)
%eigen_typemaps(Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>)
%eigen_typemaps(Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic>)
%eigen_typemaps(Eigen::Array<double, Eigen::Dynamic, 1>)
%eigen_typemaps(Eigen::Array<double, Eigen::Dynamic, Eigen::Dynamic>)

%include "ChemistryTypes.h"
%include "CrystalTypes.h"
%include "DataTypes.h"
%include "GeometryTypes.h"
%include "ImagingTypes.h"
%include "InstrumentTypes.h"
%include "UtilsTypes.h"

%include "Axis.h"
%include "RotAxis.h"
%include "TransAxis.h"
%include "Gonio.h"
%include "ComponentState.h"
%include "Component.h"
%include "Monochromator.h"
%include "Source.h"

%include "AABB.h"
%include "Ellipsoid.h"
%include "Blob3D.h"

%include "Material.h"

%template(scored_uc) std::pair<std::shared_ptr<nsx::UnitCell>, double>;
%template(indexer_solutions) std::vector<std::pair<std::shared_ptr<nsx::UnitCell>,double>>;

%include "Detector.h"
%include "MonoDetector.h"
%include "CylindricalDetector.h"
%include "FlatDetector.h"
%include "Sample.h"
%include "Diffractometer.h"
%include "Singleton.h"

namespace nsx {
   class DataReaderFactory; 
   struct tVector;
}

%include "FFTIndexing.h"

%include "Intensity.h"
%include "Peak3D.h"

%include "ConstantKernel.h"
%include "KernelFactory.h"
%include "ConvolutionKernel.h"
%include "DeltaKernel.h"
%include "AnnularKernel.h"
%include "Convolver.h"

%include "MetaData.h"
%include "IDataReader.h"
%include "DataReaderFactory.h"
%include "ILLDataReader.h"
%include "HDF5DataReader.h"
%include "DataSet.h"
%include "PeakFinder.h"
%include "MergedData.h"

%template(vector_data) std::vector<std::shared_ptr<nsx::DataSet>>;
%template(vector_peak) std::vector<std::shared_ptr<nsx::Peak3D>>;

%template(PeakSet) std::set<std::shared_ptr<nsx::Peak3D>>;
%template(MergedPeakSet) std::set<nsx::MergedPeak>;

%include "Material.h"

%include "ErfInv.h"
%include "Gaussian.h"
%include "GCD.h"
%include "Interpolator.h"
%include "Lorentzian.h"
%include "Round.h"
%include "FitParameters.h"
%include "Minimizer.h"
%include "RNG.h"
%include "Profile3d.h"

%include "EigenToVector.h"
%include "System.h"
%include "CSV.h"
%include "Enums.h"
%include "DoubleToFraction.h"
%include "Timer.h"
%include "Path.h"
%include "LMFunctor.h"
%include "RandomMatrix.h"
%include "Parser.h"
%include "MatrixParser.h"
%include "ProgressHandler.h"
%include "PeakPredictor.h"
%include "UBSolution.h"
%include "UBMinimizer.h"
%include "Refiner.h"
%include "Basis.h"

%include "Profile.h"
%include "Intensity.h"
%include "PeakIntegrator.h"
%include "UnitCell.h"
%include "ResolutionShell.h"
%include "RFactor.h"
%include "CC.h"
%include "CC.h"
%include "Peak3D.h"
%include "PeakRecord.h"
%include "Mosaic.h"
%include "FFTIndexing.h"
%include "MergedPeak.h"
%include "Peak2D.h"
%include "SpaceGroup.h"
%include "NiggliReduction.h"
%include "GruberReduction.h"
%include "SymOp.h"

%include "Vertex.h"
%include "Triangle.h"
%include "Ellipsoid.h"
%include "Face.h"
%include "MCAbsorption.h"
%include "ConvexHull.h"
%include "BlobFinder.h"
%include "AABB.h"
%include "Edge.h"
%include "Blob3D.h"
%include "IntegrationRegion.h"
%include "BrillouinZone.h"

%include "XDS.h"
%include "DataSet.h"
%include "MetaData.h"
%include "ILLDataReader.h"
%include "IDataReader.h"
%include "HDF5DataReader.h"
%include "I16DataReader.h"
%include "RawDataReader.h"
%include "TiffDataReader.h"
%include "BloscFilter.h"
%include "DataReaderFactory.h"

%include "Detector.h"
%include "DetectorFactory.h"
%include "TransAxis.h"
%include "Sample.h"
%include "ComponentState.h"
%include "FlatDetector.h"
%include "Source.h"
%include "InstrumentState.h"
%include "MultiDetector.h"
%include "Monochromator.h"
%include "MonoDetector.h"
%include "Diffractometer.h"
%include "CylindricalDetector.h"
%include "Gonio.h"
%include "DetectorEvent.h"

%template(vectorDetectorEvent) std::vector<nsx::DetectorEvent>;

%include "Axis.h"
%include "Experiment.h"
%include "Component.h"
%include "AxisFactory.h"
%include "RotAxis.h"

%include "AutoIndexer.h"

%include "Memento.h"
%include "Singleton.h"

%newobject new_double;
double* new_double();
double get_value(const double*);
%{
    double* new_double()
    {
        return new double;
    }

    double get_value(const double* ptr)
    {
        return *ptr;
    }
%}


