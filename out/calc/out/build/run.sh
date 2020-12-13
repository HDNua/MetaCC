#!/bin/bash
rm -rf CMakeCache.txt  CMakeFiles  CTestTestfile.cmake  Makefile  cmake_install.cmake  parser.tab.cc  parser.tab.hh  parser.yy.cc
cmake ..
make
