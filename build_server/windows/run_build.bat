mkdir build
cd build

set HDF5_ROOT=C:\Program Files\HDF_Group\HDF5\1.8.17
set QTDIR=C:\Qt\Qt5.6.1\5.6\msvc2015_64

set BOOST_ROOT=c:\local\boost_1_61_0
set BOOST_LIBRARYDIR=c:\local\boost_1_61_0\lib64-msvc-14.0

set FFTW_DIR=C:\Users\ci\Libraries\fftw

set PATH=%QTDIR%\bin;%PATH%
set PATH=C:\temp\pkg-config-0.26\bin;%PATH%
set PATH=C:\Users\ci\Libraries\eigen;%PATH%
set PATH=C:\Users\ci\Libraries\libtiff;%PATH%
set PATH=C:\Program Files\LLVM;%PATH%
set PATH=C:\opt\local_x64\bin;%PATH%

call "C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\vcvarsall.bat" amd64

cmake .. -G "Ninja" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INCLUDE_PATH=C:\opt\local_x64\include -DCMAKE_LIBRARY_PATH=C:\opt\local_x64\lib -DNSX_PYTHON=OFF
cmake --build . --config Release
