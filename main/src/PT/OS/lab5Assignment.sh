#!/bin/bash

read -p "Input: " ip

ip_regex="^([0-9]{1,3}\.){3}[0-9]{1,3}$"

if [[ $ip =~ $ip_regex ]]; then
    echo "Valid"
else 
    echo "Invalid"
fi