#!/bin/bash

# Prompt user for input
read -p "Enter a word: " word
read -p "Enter a letter: " letter

# Use grep to count occurrences of the letter in the word
occurrences=$(echo "$word" | grep -o "$letter" | wc -l)

# Print the result
echo "Occurrences of '$letter' in '$word': $occurrences"
