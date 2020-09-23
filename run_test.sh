#!/bin/bash

IFS=$'\n'

for i in `cat input.txt`; do 
    echo "Eredmeny: $i,"
    echo "$i" | ./a.out  
done 