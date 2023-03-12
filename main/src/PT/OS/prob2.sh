#!/bin/bash

# check if correct number of arguments are passed
if [ $# -ne 2 ]; then
    echo "Usage: $0 not enough args"
    exit 1
fi

# set variables for directory and output file
dir=$1
out_file=$2

# scan the directory for .txt files and count characters
total=0

for file in $(find $dir -type f -name "*.txt"); do
    count=$(wc -m < "$file")
    echo "$file $count" >> "$out_file"
    total=$((total+count))
done

# write total character count to output file
echo "TOTAL $total" >> "$out_file"