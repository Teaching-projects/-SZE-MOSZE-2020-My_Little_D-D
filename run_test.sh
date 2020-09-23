#!/bin/bash

IFS=$'\n'

for i in `cat input.txt`; do 
    echo "Eredmeny: $i, \t"
    echo "$i" | ./a.out  
done 