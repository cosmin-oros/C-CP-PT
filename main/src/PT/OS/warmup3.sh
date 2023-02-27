#!/bin/bash

# get the current time
hour=$(date +%H)

# get the user's alias using whoami
username=$(whoami)

# determine the greeting based on the time
if [ $hour -ge 6 ] && [ $hour -lt 12 ]; then
  greeting="Good morning"
elif [ $hour -ge 12 ] && [ $hour -lt 18 ]; then
  greeting="Good afternoon"
elif [ $hour -ge 18 ] && [ $hour -lt 22 ]; then
  greeting="Good evening"
else
  greeting="Good night"
fi

echo "$greeting, $username!"