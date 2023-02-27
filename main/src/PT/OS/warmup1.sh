#!/bin/bash

# Check if exactly 3 arguments are passed in
if [ $# -ne 3 ]; then
  echo "Not enough args"
  exit 1
fi

if [ $1 -gt $2 ] && [ $1 -gt $3 ]; then
  echo $1
elif [ $2 -gt $1 ] && [ $2 -gt $3 ]; then
  echo $2
else
  echo $3
fi