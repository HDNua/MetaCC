#!/bin/bash
if [ -d out ]
then
	mv out out_
	cp -r template out
fi
./metacc lyc < calc.list
cd out/build
cmake ..
make
exit
