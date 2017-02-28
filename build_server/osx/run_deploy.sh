#!/bin/bash

cd ${CI_PROJECT_DIR}

mkdir build
cd build

cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_QTAPPS=ON -DCMAKE_INSTALL_PREFIX=. -DCMAKE_PREFIX_PATH=/usr/local/Cellar/qt5/5.6.0/ ..
make -j4 -l4
make install

declare -x CPLUS_INCLUDE_PATH=/usr/local/include:/usr/local/opt/eigen/include/eigen3:/usr/local/opt/boost/include:${CI_PROJECT_DIR}/build/include/NSXTool
declare -x LIBRARY_PATH=${CI_PROJECT_DIR}/build/nsxlib:/usr/local/opt/boost/lib/:/usr/local/opt/fftw/lib/

mkdir qmake-build
cd qmake-build

/usr/local/opt/qt5/bin/qmake ${CI_PROJECT_DIR}/build/apps/NSXQt/NSXQt.pro CONFIG+=release
make -j4 -l4

/usr/local/opt/qt5/bin/macdeployqt nsxtool.app/ -dmg