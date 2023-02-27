#!/bin/bash

# Check if exactly 3 arguments are passed in
if [ $# -ne 3 ]; then
  echo "Not enough args"
  exit 1
fi

num1=$1
operator=$2
num2=$3

# check if the operator is valid
if [[ "$operator" != "+" && "$operator" != "-" && "$operator" != "*" && "$operator" != "/" ]]; then
  echo "Invalid operator: $operator"
  exit 1
fi

# case statement for the operation on the 2 numbers
case $operator in
  "+") result=$((num1 + num2));;
  "-") result=$((num1 - num2));;
  "*") result=$((num1 * num2));;
  "/") result=$((num1 / num2));;
esac

echo "$num1 $operator $num2 = $result"