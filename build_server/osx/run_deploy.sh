#!/bin/bash

declare -x QTDIR=/usr/local/Cellar/qt5/5.6.0

cd ${CI_PROJECT_DIR}

mkdir build
cd build

cmake -G"Ninja" -DCMAKE_BUILD_TYPE=Release -DNSX_PYTHON=ON -DBUILD_NSX_APPS=ON -DCMAKE_INSTALL_PREFIX=. -DCMAKE_PREFIX_PATH="${QTDIR};/usr/local/Cellar/gsl/2.3" ..

cmake --build . --config Release --target package
