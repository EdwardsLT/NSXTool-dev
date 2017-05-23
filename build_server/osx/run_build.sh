#!/bin/bash

cd ${CI_PROJECT_DIR}
mkdir ./build
cd build

cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Release -DBUILD_QTAPPS=ON -DCMAKE_PREFIX_PATH="/usr/local/Cellar/python/2.7.11/Frameworks/Python.framework/Versions/2.7;/usr/local/Cellar/qt5/5.6.0;/usr/local/Cellar/gsl/2.3" -DCMAKE_INSTALL_PREFIX=. -DNSX_PYTHON=ON -DNSX_PYTHON3=OFF ..
cmake --build . --config Release
cmake --build . --config Release --target install
