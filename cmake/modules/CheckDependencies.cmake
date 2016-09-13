
# find clang
#if ( BUILD_WITH_CLANG )
#    include(FindClang)
#endif( BUILD_WITH_CLANG )


###### Find boost libraries  ##############
find_package(Boost 1.54.0 COMPONENTS date_time system filesystem unit_test_framework REQUIRED)
if(Boost_FOUND)
    include_directories("${Boost_INCLUDE_DIRS}")
    set(Boost_USE_STATIC_LIBS OFF)
    set(Boost_USE_MULTITHREADED ON)
    set(Boost_USE_STATIC_RUNTIME OFF)
    message(STATUS "Found boost: " ${Boost_INCLUDE_DIRS})
    message(STATUS "Boost" ${Boost_LIBRARIES})
elseif(NOT Boost_FOUND)
    message(FATAL_ERROR "Unable to find correct Boost version. Did you set BOOST_ROOT?")
endif()

###### Find OPENMP
find_package(OpenMP)

#if (OPENMP_FOUND)
#    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#endif()

###### Find the Eigen3
find_package(Eigen3 REQUIRED)
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIR})

###### Search the HDF5 library
find_package(HDF5 COMPONENTS CXX REQUIRED)

# manually fix problem with windows build
if(NOT HDF5_LIBRARIES)
  set(HDF5_LIBRARIES "")
  find_library(HDF5_LIBRARY_TEMP libszip)
  set(HDF5_LIBRARIES "${HDF5_LIBRARIES};${HDF5_LIBRARY_TEMP}")

  find_library(HDF5_LIBRARY_TEMP libzlib)
  set(HDF5_LIBRARIES "${HDF5_LIBRARIES};${HDF5_LIBRARY_TEMP}")

  find_library(HDF5_LIBRARY_TEMP libhdf5)
  set(HDF5_LIBRARIES "${HDF5_LIBRARIES};${HDF5_LIBRARY_TEMP}")

  find_library(HDF5_LIBRARY_TEMP libhdf5_cpp)
  set(HDF5_LIBRARIES "${HDF5_LIBRARIES};${HDF5_LIBRARY_TEMP}")
endif()

include_directories("${HDF5_INCLUDE_DIRS}")

if ( HDF5_INCLUDE_DIRS AND HDF5_LIBRARIES )
   message("HDF5 found: include dir is ${HDF5_INCLUDE_DIRS} and library is ${HDF5_LIBRARIES} located in ${HDF5_LIBRARY_DIRS}")
else()
   messagE("ERROR: HDF5 not found")
endif()


find_package(Blosc REQUIRED)
if (BLOSC_FOUND==True)
        message("Blosc library found, already installed on the system")
else()
        #### Internal dependencies
        add_subdirectory(externals/c-blosc)
        message("Blosc library not found, will build from internal resources")
endif()

###### TIFF library
find_package(TIFF REQUIRED)
include_directories(${TIFF_INCLUDE_DIR})


# find_path(FFTW_INCLUDE_DIR fftw3.h)
# include_directories(${FFTW_INCLUDE_DIR})
# find_library(FFTW_LIBRARIES NAMES fftw3 libfftw3 fftw3-3 libfftw3-3)

find_package(FFTW REQUIRED)
include_directories(${FFTW_INCLUDE_DIR})

# GNU scientific library
find_package(GSL)

if(GSL_FOUND)
  include_directories(${GSL_INCLUDE_DIR})

  set(temp_string ${GSL_VERSION})
  string(REGEX REPLACE "([0-9]+)\\.([0-9]+)(\\.([0-9]+))?" "\\1" gsl_version_major ${temp_string})
  string(REGEX REPLACE "([0-9]+)\\.([0-9]+)(\\.([0-9]+))?" "\\2" gsl_version_minor ${temp_string})
  #string(REGEX REPLACE "([0-9]+)\\.([0-9]+)(\\.([0-9]+))?" "\\4" gsl_version_subminor ${temp_string})
  

  message("GSL_VERSION_MAJOR is ${gsl_version_major}")
  message("GSL_VERSION_MINOR is ${gsl_version_minor}")
  #message("GSL_VERSION_SUBMINOR is ${gsl_version_subminor}")

  add_definitions(-DNSXTOOL_GSL_FOUND=1)
  add_definitions(-DNSXTOOL_GSL_VERSION_MAJOR=${gsl_version_major})
  add_definitions(-DNSXTOOL_GSL_VERSION_MINOR=${gsl_version_minor})
    
  else()
  message(WARNING "GSL library not found -- will use Eigen/unsupported for Levenberg-Marquardt algorithm")
endif()





