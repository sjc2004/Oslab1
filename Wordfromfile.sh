#!/bin/bash

# Prompt user for input
read -p "Enter a word: " target_word
read -p "Enter the file name: " file_name

# Check if the file exists
if [ -f "$file_name" ]; then
    # Use grep to count occurrences of the word in the file
    occurrences=$(grep -o -w "$target_word" "$file_name" | wc -l)

    # Print the result
    echo "Occurrences of '$target_word' in '$file_name': $occurrences"
else
    echo "Error: File '$file_name' not found."
fi
