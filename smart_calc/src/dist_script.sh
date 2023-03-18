#!/bin/sh

mkdir SmartCalc_dist
cd SmartCalc_dist
cp ../*.c .
cp ../*.h .
cp ../*.cpp .
cp ../*.ui .
cp ../CMakeLists.txt .
cp ../CMakeLists.txt.user .
cp ../*.sh .
cp ../readme.html .
cp ../Makefile .
cd ..

tar -czf SmartCalc_arch.tar.gz SmartCalc_dist/
