echo -n "Enter space-separated numbers: "
read input_numbers

# Use 'read' to split the input into an array
IFS=" " read -ra numbers <<< "$input_numbers"

# Sort the array in descending order using 'sort' command
sorted_numbers=$(for number in "${numbers[@]}"; do
    echo "$number"
done | sort -nr)

echo "Sorted numbers in descending order: $sorted_numbers"
