#!/bin/bash

IFS=$'\n'

for i in `cat input.txt`; do 
    echo $i | xargs ./a.exe >> output.txt
done 