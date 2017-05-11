#!/bin/bash

cd ${CI_PROJECT_DIR}

cd build

cmake -G"Ninja" -DCMAKE_BUILD_TYPE=Release -DENABLE_CPACK=ON -DBUILD_QTAPPS=ON .

cmake --build . --config Release --target package

