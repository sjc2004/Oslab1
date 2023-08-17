filename="student_info.txt"

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
            cat "$filename"
            ;;
        b)
            read -p "Enter Roll Number: " roll_number
            grep "^$roll_number," "$filename"
            ;;
        c)
            read -p "Enter Roll Number to delete: " roll_number
            sed -i "/^$roll_number,/d" "$filename"
            echo "Entry deleted successfully"
            ;;
        d)
            read -p "Enter Roll Number: " roll_number
            read -p "Enter Name: " name
            read -p "Enter City: " city
            echo "$roll_number,$name,$city" >> "$filename"
            echo "Entry added successfully"
            ;;
        e)
            read -p "Enter Roll Number to update: " roll_number
            entry=$(grep "^$roll_number," "$filename")
            if [ -n "$entry" ]; then
                read -p "Enter new Name: " new_name
                read -p "Enter new City: " new_city
                sed -i "s/^$roll_number,.*/$roll_number,$new_name,$new_city/" "$filename"
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
