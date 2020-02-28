#!/bin/bash

sources="../msp.cpp ../core/src/baseobject.cpp ../core/src/basesaver.cpp"

mkdir -p build
cd build
g++ $sources -o msp
