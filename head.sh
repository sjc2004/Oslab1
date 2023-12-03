#!/bin/bash

echo "Enter the filename: "
read filename

if [ -f "$filename" ]; then
    count=0
    while IFS= read -r line && [ "$count" -lt 10 ]; do
        echo "$line"
        ((count++))
    done < "$filename"
else
    echo "File not found."
fi
