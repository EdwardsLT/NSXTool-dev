#!/bin/bash

cd ${CI_PROJECT_DIR}/build

export CTEST_OUTPUT_ON_FAILURE=1
ctest -j4 -l4

