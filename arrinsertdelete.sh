#!/bin/bash

# Function to insert an element into an array at a specific position
insert_element() {
    if [ $1 -le ${#array[@]} ] && [ $1 -ge 0 ]; then
        array=("${array[@]:0:$1}" "$2" "${array[@]:$1}")
    else
        echo "Error: Invalid position for insertion."
    fi
}

# Function to delete an element from an array at a specific position
delete_element() {
    if [ $1 -lt ${#array[@]} ] && [ $1 -ge 0 ]; then
        array=("${array[@]:0:$1}" "${array[@]:$(( $1 + 1 ))}")
    else
        echo "Error: Invalid position for deletion."
    fi
}

# Read array elements from user input
read -p "Enter array elements (space-separated): " -a array

# Display the initial array
echo "Initial Array: ${array[@]}"

# Read position and element to insert from user
read -p "Enter position to insert: " insert_position
read -p "Enter element to insert: " insert_element_value

# Insert the element at the specified position
insert_element $insert_position "$insert_element_value"
if [ $? -eq 0 ]; then
    echo "Array after insertion: ${array[@]}"
fi

# Read position to delete from user
read -p "Enter position to delete: " delete_position

# Delete the element at the specified position
delete_element $delete_position
if [ $? -eq 0 ]; then
    echo "Array after deletion: ${array[@]}"
fi
