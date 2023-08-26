filename="student_info.txt"
tempfile="temp_student_info.txt"

while true; do
    echo "Menu:"
    echo "a) Display the contents of the whole file"
    echo "b) Display the information of a student with a specific Roll Number"
    echo "c) Delete the entry of a student with a specific Roll Number"
    echo "d) Add a new entry in the file"
    echo "e) Update an entry of a student with a specific Roll Number"
    echo "q) Quit"

    read -p "Enter your choice: " choice

    case "$choice" in
        a)
            echo "Contents of the file:"
            if [ -s "$filename" ]; then
                echo -e "Roll no.\t|\tName\t|\tCity\t|\tSGPA"
                cat "$filename" | while read line; do
                    roll=$(echo "$line" | cut -d "|" -f 1)
                    name=$(echo "$line" | cut -d "|" -f 2)
                    city=$(echo "$line" | cut -d "|" -f 3)
                    sgpa=$(echo "$line" | cut -d "|" -f 4)
                    echo -e "$roll\t|\t$name\t|\t$city\t|\t$sgpa"
                done
            else
                echo "No records found"
            fi
            ;;
        b)
            read -p "Enter Roll Number: " roll_number
            if grep -q "^$roll_number|" "$filename"; then
                grep "^$roll_number|" "$filename"
            else
                echo "Roll Number not found"
            fi
            ;;
        c)
            read -p "Enter Roll Number to delete: " roll_number
            if grep -q "^$roll_number|" "$filename"; then
                grep -v "^$roll_number|" "$filename" > "$tempfile"
                mv "$tempfile" "$filename"
                echo "Entry deleted successfully"
            else
                echo "Roll Number not found"
            fi
            ;;
        d)
            read -p "Enter Roll Number: " roll_number
            read -p "Enter Name: " name
            read -p "Enter City: " city
            read -p "Enter SGPA: " sgpa
            echo "$roll_number|\t$name\t|\t$city\t|\t$sgpa" >> "$filename"
            echo "Entry added successfully"
            ;;
        e)
            read -p "Enter Roll Number to update: " roll_number
            entry=$(grep "^$roll_number|" "$filename")
            if [ -n "$entry" ]; then
                read -p "Enter new Name: " new_name
                read -p "Enter new City: " new_city
                read -p "Enter new SGPA: " new_sgpa
                grep -v "^$roll_number|" "$filename" > "$tempfile"
                echo "$roll_number|\t$new_name\t|\t$new_city\t|\t$new_sgpa" >> "$tempfile"
                mv "$tempfile" "$filename"
                echo "Entry updated successfully"
            else
                echo "Roll Number not found"
            fi
            ;;
        q)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid choice, please select a valid option."
            ;;
    esac
done
