# Initialize the array
array=("apple" "banana" "cherry" "date" "elderberry")

# Print the original array
echo "Original array: ${array[@]}"

# Index of the element to be deleted (0-based index)
delete_index=2

# Check if the index is within bounds
if [ "$delete_index" -lt 0 ] || [ "$delete_index" -ge ${#array[@]} ]; then
    echo "Invalid index."
    exit 1
fi

# Remove the element at the specified index
unset "array[$delete_index]"

# Create a new array without empty elements
new_array=()
for element in "${array[@]}"; do
    [ -n "$element" ] && new_array+=("$element")
done

# Print the new array
echo "Array after deletion: ${new_array[@]}"
