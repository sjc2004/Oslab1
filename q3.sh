echo -n "Enter the file name: "
read file_name

if [ ! -f "$file_name" ]; then
    echo "File not found."
    exit 1
fi

echo -n "Enter the starting line number: "
read start_line

echo -n "Enter the number of lines to display: "
read num_lines

end_line=$((start_line + num_lines - 1))

if [ "$end_line" -gt "$(wc -l < "$file_name")" ]; then
    echo "Not enough lines in the file to display."
    exit 1
fi

# Using 'sed' to extract the desired lines from the file
sed -n "${start_line},${end_line}p" "$file_name"
