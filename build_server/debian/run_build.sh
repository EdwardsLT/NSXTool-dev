#!/bin/bash

cd ${CI_PROJECT_DIR}

mkdir ./build
cmake -DCMAKE_BUILD_TYPE=Release -DENABLE_CPACK=OFF -DBUILD_QTAPPS=OFF -DCMAKE_INSTALL_PREFIX=./build
make -j2 -l2
make install

