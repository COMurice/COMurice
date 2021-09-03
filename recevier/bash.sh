#!/bin/bash

for i in $(seq 1 100)
do
	cp test.c test${i}.c
done
