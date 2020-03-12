#!/bin/bash

src_structured="../structured/src/rectgrid.cpp"
src_core="../core/src/baseobject.cpp ../core/src/basesaver.cpp ../core/src/vector.cpp ../core/src/matrix.cpp"
src_acoustic="../acoustic/src/acousticnode.cpp"

mkdir -p build
cd build
g++ ../msp.cpp $src_core $src_structured $src_acoustic -o msp
