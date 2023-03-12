#!/bin/bash

# check that we have the right number of arguments
if [[ $# -ne 2 ]]; then
    echo "Usage: $0 not enough arguments"
    exit 1
fi

# get the directory and character from the arguments
dir=$1
c=$2

# check that the directory exists and is a directory
if [[ ! -d $dir ]]; then
    echo "Error: $dir is not a directory"
    exit 1
fi

# check that the character is valid
if [[ $c != "r" && $c != "w" && $c != "x" ]]; then
    echo "Error: $c is not a valid character"
    exit 1
fi

# set the permissions for each .txt file in the directory
find $dir -name "*.txt" -type f -print0 | while read -d $'\0' file; do
    chmod u+$c $file
done