echo -n "Enter the main string: "
read main_string

echo -n "Enter the substring to search: "
read substring

# Use 'grep' to find the position of the substring within the main string
position=$(echo "$main_string" | grep -b -o "$substring" | cut -d ':' -f 1)

if [ -n "$position" ]; then
    echo "Substring '$substring' found at position $position."
else
    echo "Substring '$substring' not found in the main string."
fi
