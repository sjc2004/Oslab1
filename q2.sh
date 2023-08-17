echo -n "Enter a string: "
read input_string

# Remove non-alphanumeric characters and convert to lowercase
cleaned_string=$(echo "$input_string" | tr -d -c '[:alnum:]' | tr '[:upper:]' '[:lower:]')

# Reverse the cleaned string
reversed_string=$(echo "$cleaned_string" | rev)

if [ "$cleaned_string" = "$reversed_string" ]; then
    echo "The input string is a palindrome."
else
    echo "The input string is not a palindrome."
fi

