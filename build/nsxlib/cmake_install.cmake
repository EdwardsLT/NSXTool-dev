# Install script for directory: /home/lewisedwards/bin/nsxtool-dev/nsxlib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xLIBx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnsx.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnsx.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnsx.so"
         RPATH "/usr/local/lib:/usr/lib/x86_64-linux-gnu/hdf5/serial")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/lewisedwards/bin/nsxtool-dev/build/nsxlib/libnsx.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnsx.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnsx.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnsx.so"
         OLD_RPATH "/usr/lib/x86_64-linux-gnu/hdf5/serial:/usr/local/lib:"
         NEW_RPATH "/usr/local/lib:/usr/lib/x86_64-linux-gnu/hdf5/serial")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnsx.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDEVx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/nsxlib" TYPE FILE FILES
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/auto_indexing/AutoIndexer.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/auto_indexing/FFTIndexing.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/auto_indexing/GruberReduction.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/auto_indexing/NiggliReduction.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/auto_indexing/UserDefinedUnitCellIndexer.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/chemistry/ChemicalFormulaParser.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/chemistry/ChemistryTypes.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/chemistry/IsotopeDatabaseManager.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/chemistry/Material.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/crystal/CrystalTypes.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/crystal/Intensity.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/crystal/MergedPeak.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/crystal/NiggliCharacter.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/crystal/Peak.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/crystal/PeakData.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/crystal/PeakFilter.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/crystal/ResolutionShell.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/crystal/SpaceGroup.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/crystal/SymOp.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/crystal/UnitCell.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/data/BloscFilter.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/data/DataReaderFactory.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/data/DataSet.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/data/DataTypes.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/data/FakeDataReader.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/data/HDF5DataReader.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/data/HDF5MetaDataReader.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/data/IDataReader.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/data/ILLDataReader.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/data/MergedData.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/data/MetaData.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/data/RawDataReader.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/data/TiffDataReader.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/geometry/AABB.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/geometry/Blob3D.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/geometry/BrillouinZone.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/geometry/ConvexHull.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/geometry/DirectVector.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/geometry/Edge.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/geometry/Ellipsoid.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/geometry/Face.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/geometry/GeometryTypes.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/geometry/Mask.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/geometry/MillerIndex.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/geometry/Octree.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/geometry/PeakCoordinateSystem.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/geometry/ReciprocalVector.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/geometry/Triangle.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/geometry/Vertex.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/Axis.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/AxisFactory.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/Component.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/CylindricalDetector.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/Detector.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/DetectorEvent.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/DetectorFactory.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/Diffractometer.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/Experiment.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/FlatDetector.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/Gonio.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/InstrumentState.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/InstrumentTypes.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/InterpolatedState.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/Monochromator.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/RotAxis.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/Sample.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/Source.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/instrument/TransAxis.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/integration/GaussianIntegrator.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/integration/IPeakIntegrator.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/integration/ISigmaIntegrator.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/integration/IntegrationRegion.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/integration/MeanBackgroundIntegrator.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/integration/PixelSumIntegrator.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/integration/Profile1D.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/integration/Profile1DIntegrator.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/integration/Profile3D.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/integration/Profile3DIntegrator.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/integration/ShapeIntegrator.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/integration/ShapeLibrary.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/kernel/Factory.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/kernel/Singleton.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/logger/AggregateStreamWrapper.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/logger/IStreamWrapper.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/logger/LogFileStreamWrapper.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/logger/Logger.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/logger/StdStreamWrapper.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/mathematics/FitParameters.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/mathematics/JonesSymbolParser.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/mathematics/MathematicsTypes.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/mathematics/MatrixOperations.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/mathematics/Minimizer.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/monte-carlo/MCAbsorption.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/monte-carlo/mosaic.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/monte-carlo/mozaictester.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/peak_find/AnnularConvolver.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/peak_find/AtomicConvolver.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/peak_find/BoxConvolver.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/peak_find/ConvolverFactory.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/peak_find/DeltaConvolver.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/peak_find/EnhancedAnnularConvolver.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/peak_find/GaussianConvolver.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/peak_find/IConvolver.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/peak_find/PeakFinder.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/peak_find/RadialConvolver.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/physics/PhysicalUnit.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/refining/RefinementBatch.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/refining/Refiner.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/statistics/CC.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/statistics/IMergedPeakStatistic.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/statistics/RFactor.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/stl/Any.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/stl/Variant.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/task/ITask.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/utils/CSV.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/utils/DoubleToFraction.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/utils/EigenToVector.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/utils/Enums.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/utils/Macros.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/utils/MatrixParser.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/utils/NSXTest.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/utils/Parser.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/utils/Path.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/utils/ProgressHandler.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/utils/StringIO.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/utils/System.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/utils/Units.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/utils/UtilsTypes.h"
    "/home/lewisedwards/bin/nsxtool-dev/nsxlib/utils/YAMLType.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDEVx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/nsxlib" TYPE FILE FILES
    "/home/lewisedwards/bin/nsxtool-dev/build/nsxlib/generated/Resources.h"
    "/home/lewisedwards/bin/nsxtool-dev/build/nsxlib/generated/SingleResourceBioDiff2500.h"
    "/home/lewisedwards/bin/nsxtool-dev/build/nsxlib/generated/SingleResourceBioDiff5000.h"
    "/home/lewisedwards/bin/nsxtool-dev/build/nsxlib/generated/SingleResourceD10.h"
    "/home/lewisedwards/bin/nsxtool-dev/build/nsxlib/generated/SingleResourceD19.h"
    "/home/lewisedwards/bin/nsxtool-dev/build/nsxlib/generated/SingleResourceD9.h"
    "/home/lewisedwards/bin/nsxtool-dev/build/nsxlib/generated/SingleResourceD9_large.h"
    "/home/lewisedwards/bin/nsxtool-dev/build/nsxlib/generated/SingleResourceD9_large_lifting_arm.h"
    "/home/lewisedwards/bin/nsxtool-dev/build/nsxlib/generated/SingleResourceD9_lifting_arm.h"
    "/home/lewisedwards/bin/nsxtool-dev/build/nsxlib/generated/SingleResourceI16.h"
    "/home/lewisedwards/bin/nsxtool-dev/build/nsxlib/generated/SingleResourceIsotopes.h"
    "/home/lewisedwards/bin/nsxtool-dev/build/nsxlib/generated/Version.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDATAx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nsxtool" TYPE DIRECTORY FILES "/home/lewisedwards/bin/nsxtool-dev/resources/databases" REGEX "/\\.git$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDATAx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nsxtool" TYPE DIRECTORY FILES "/home/lewisedwards/bin/nsxtool-dev/resources/instruments" REGEX "/\\.git$" EXCLUDE)
endif()

