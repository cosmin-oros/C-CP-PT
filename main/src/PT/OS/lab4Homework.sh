#!/bin/bash

dir=$1
regex=$2
output_file="output1.txt"
link_count=0

# Traverse the directory and its subdirectories
find "$dir" -type f | while read file; do
    # Count symbolic links
    if [[ -L "$file" ]]; then
        ((link_count++))
    else
        # Search for regex pattern in regular files
        if [[ -f "$file" ]]; then
            if grep -q "$regex" "$file"; then
                echo "$file" >> "$output_file"
            fi
        fi
    fi
done

# Print count of symbolic links
echo "Total symbolic links found: $link_count"