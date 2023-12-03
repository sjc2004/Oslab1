#!/bin/bash

echo "Enter the filename: "
read filename

if [ -f "$filename" ]; then
    total_lines=$(wc -l < "$filename")
    start_line=$((total_lines - 9))
    
    if [ "$start_line" -le 0 ]; then
        start_line=1
    fi

    awk "NR >= $start_line" "$filename"
else
    echo "File not found."
fi
#!/bin/bash

#echo "Enter the filename: "
#read filename

#if [ -f "$filename" ]; then
    tail -n 10 "$filename"
#else
    echo "File not found."
#fi
