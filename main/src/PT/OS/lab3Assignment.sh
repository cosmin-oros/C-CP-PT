#!/bin/bash

if [ $# -lt 4 ]; then
  echo "Usage: "
  for arg in "$@"
  do
    echo "$arg "
  done
  exit 1
fi

shift 2

count=0

for arg in "$@"
do
if [ $arg -gt 10 ]; then
    (( count++ ))
fi
done

echo $count

sum=0

for arg in "$@"
do
    (( sum += $arg ))
done

echo $sum

digits=0


