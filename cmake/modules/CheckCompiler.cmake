#---------------------------------------------------------------------------------------------------
#  CheckCompiler.cmake
#---------------------------------------------------------------------------------------------------

 
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_definitions( -std=c++11)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  set(MSVC TRUE)
else()
  message(WARNING "C++ compiler not recognized")
endif()

message(STATUS "Using compiler `${CMAKE_CXX_COMPILER_ID}` with flags ${CMAKE_CXX_FLAGS}")



if ( BUILD_WITH_DEBUG_INFO )
    if (CMAKE_COMPILER_IS_GNUCXX)
        add_definitions(-g)
    endif(CMAKE_COMPILER_IS_GNUCXX)
endif( BUILD_WITH_DEBUG_INFO )


if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(
        -Wall
        -Wno-ignored-attributes # ignore annoying warnings caused by Eigen library
        -Wno-misleading-indentation # ignore annoying warnings caused by Eigen library
        -Wno-deprecated-declarations # ignore annoying warnings caused by Eigen library
        -std=c++11
        #-fopenmp
        -pthread
        -DEIGEN_FFTW_DEFAULT
    )
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  message("Configuring for build type 'Release'")
if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(
    -msse2
    -DNDEBUG
    #-D__GXX_EXPERIMENTAL_CXX0X__
    -funroll-loops
    -mfpmath=sse
    -ftree-vectorize
    -O2
    )
  endif()
  message("Configuring for build type 'Release'")
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
  message("Configuring for build type 'Debug'")
  if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Og -g")
  else()
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1 -g")
  endif()
else()
  message("Warning: build type ${CMAKE_BUILD_TYPE} is unrecognized")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    add_definitions(-std=c++11)
endif()


# Disable auto-linking to allow dynamic linking with MSVC
if(WIN32 AND MSVC)
    add_definitions(-DBOOST_ALL_NO_LIB)
    add_definitions(-D_USE_MATH_DEFINES)
    add_definitions(-DNSXTOOL_EXPORT)
    add_definitions(-DH5_BUILT_AS_DYNAMIC_LIB)
endif()


if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  # add_definitions(-std=c++11)
  #  -stdlib=libc++
endif()
