#!/bin/bash

BUILD_DIR="build"
GENERATOR=""

if [[ $OSTYPE == "darwin"* ]]; then
    GENERATOR="-G Xcode"
fi

cmake $GENERATOR -S . -B $BUILD_DIR&&cmake --build $BUILD_DIR --config Release
