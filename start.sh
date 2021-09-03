#!/bin/bash

./recevier_clang & 
./compile_clang &

while :
do
        process=`ps -e | grep compile_clang`
	if [ -z "$process" ]; then
		./compile_clang &
	fi 
	process=`ps -e | grep recevier_clang`
	if [ -z "$process" ]; then
		./recevier_clang & 
	fi 
done
