#!/bin/bash

while read text 
do
    
if echo "$text" | grep '[A-Z]'; then
  echo "Text contains uppercase letters."
fi

if echo "$text" | grep '[a-z]'; then
  echo "Text contains lowercase letters."
fi

if echo "$text" | grep '[0-9]'; then
  echo "Text contains digits."
fi

if echo "$text" | grep ' '; then
  echo "Text contains spaces."
fi

if echo "$text" | grep ','; then
  echo "Text contains commas."
fi

if echo "${text:0:1}" | grep '[A-Z]'; then
  echo "Text starts with upper case."
fi

done

