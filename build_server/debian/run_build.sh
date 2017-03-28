#!/bin/bash

cd ${CI_PROJECT_DIR}

mkdir ./build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DENABLE_CPACK=OFF -DBUILD_QTAPPS=ON -DCMAKE_INSTALL_PREFIX=./ ..
make -j8 -l8
make install

