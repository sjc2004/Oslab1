#!/bin/bash

echo "Enter the filename: "
read filename

if [ -f "$filename" ]; then
    word_count=$(wc -w < "$filename")
    echo "Word count in $filename: $word_count"
else
    echo "File not found."
fi
