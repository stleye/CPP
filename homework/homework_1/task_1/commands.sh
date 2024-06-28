#!/bin/bash

wc -l data.dat
grep -E "d.lor" data.dat | wc -l
wc -w data.dat
grep -o "\bmol\w*" data.dat | wc -l
