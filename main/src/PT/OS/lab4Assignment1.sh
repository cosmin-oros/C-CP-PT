#!/bin/bash

cond=0

while [ $cond -lt 10 ]; do
    read -p "Input: " text
if echo "$text" | grep -q '[A-Z]'; then
  echo "Text contains uppercase letters."
fi

if echo "$text" | grep -q '[a-z]'; then
  echo "Text contains lowercase letters."
fi

if echo "$text" | grep -q '[0-9]'; then
  echo "Text contains digits."
fi

if echo "$text" | grep -q ' '; then
  echo "Text contains spaces."
fi

if echo "$text" | grep -q ','; then
  echo "Text contains commas."
fi

if echo "${text:0:1}" | grep -q '[A-Z]'; then
  echo "Text starts with upper case."
fi

done

