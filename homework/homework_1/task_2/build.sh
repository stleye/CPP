#!/bin/bash

INCLUDE_DIR=include
SRC_DIR=src
RESULTS_DIR=results
BUILD_DIR=build
INSTALL_DIR=install

mkdir -p $BUILD_DIR
mkdir -p $INSTALL_DIR
mkdir -p $INSTALL_DIR/lib
mkdir -p $RESULTS_DIR/bin
mkdir -p $RESULTS_DIR/dir

clang++ -I$INCLUDE_DIR -std=c++17 -c $SRC_DIR/main.cpp -o $BUILD_DIR/main.o
clang++ -I$INCLUDE_DIR -std=c++17 -c $SRC_DIR/subtract.cpp -o $BUILD_DIR/subtract.o
clang++ -I$INCLUDE_DIR -std=c++17 -c $SRC_DIR/sum.cpp -o $BUILD_DIR/sum.o

ar rcs $BUILD_DIR/libip_arithmetic.a $BUILD_DIR/subtract.o $BUILD_DIR/sum.o

clang++ $BUILD_DIR/main.o $BUILD_DIR/subtract.o $BUILD_DIR/sum.o -o $BUILD_DIR/test_ipb_arithmetic

cp $BUILD_DIR/test_ipb_arithmetic $RESULTS_DIR/bin
cp $BUILD_DIR/libip_arithmetic.a $RESULTS_DIR/lib

cp -r $INCLUDE_DIR $INSTALL_DIR
cp $BUILD_DIR/libip_arithmetic.a $INSTALL_DIR/lib

echo "Build complete."