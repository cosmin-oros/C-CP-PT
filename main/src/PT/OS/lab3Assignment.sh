#!/bin/bash

# check if there are more than 3 arguments
if [ $# -lt 4 ]; then
  echo "Usage: "
  for arg in "$@"
  do
    echo "$arg "
  done
  exit 1
fi

# save the directory and the text file
direc=$1
file=$2

shift 2

count=0

# count how many numbers are larger than 10
for arg in "$@"
do
if [ $arg -gt 10 ]; then
    (( count++ ))
fi
done

echo $count

sum=0

# get the sum of all the arguments
for arg in "$@"
do
    (( sum += $arg ))
done

echo $sum

# print the number of digits of the sum
echo -n $sum | wc -m

# check if the file is a regular file
if [ -f "$file" ]
then
  date=$(date +"%d-%m-%Y")
  echo "$count $sum $date" >> "$file"
else
  echo "$file is not a regular file"
fi

# retrieve all the files with .txt entension and print the contents of them
for txtFile in "$direc"/*.txt
do
  echo "Contents of $txtFile:"
  cat "$txtFile"
  echo ""
done