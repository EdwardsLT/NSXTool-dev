set PATH=%QTDIR%\bin;%PATH%
set BOOST_ROOT=c:\local\boost_1_61_0
set BOOST_LIBRARYDIR=c:\local\boost_1_61_0\lib64-msvc-14.0
set FFTW_DIR=C:\Users\ci\Libraries\fftw

set PATH=C:\Users\ci\Libraries\eigen;%PATH%
set PATH=C:\Users\ci\Libraries\libtiff;%PATH%
set PATH=C:\Program Files\LLVM;%PATH%

set PATH=%BOOST_LIBRARYDIR%;%PATH%
set PATH=%FFTW_DIR%;%PATH%
set PATH=C:\Users\ci\Libraries\libtiff\lib;%PATH%
set PATH=C:\Program Files\HDF_Group\HDF5\1.8.17\bin;%PATH%
set PATH=%BUILD_DIR%\nsxlib\Release;%PATH%

cd %CI_PROJECT_DIR%\build

ctest -V
