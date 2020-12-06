#!/bin/bash
./metacc lyc < calc.list
cd out/build
cmake ..
make
