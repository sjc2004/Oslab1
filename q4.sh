while true; do
    echo "Menu:"
    echo "1. Number of presently active users"
    echo "2. Display some desired number of lines from top of a file"
    echo "3. Update access time of a given file to current time"
    echo "4. Exit"
    read -p "Enter your choice: " choice

    case $choice in
        1)
            active_users=$(who | wc -l)
            echo "Number of active users: $active_users"
            ;;
        2)
            read -p "Enter the file path: " file_path
            read -p "Enter the number of lines to display: " num_lines
            if [ -f "$file_path" ]; then
                echo "Top $num_lines lines from $file_path:"
                head -n $num_lines $file_path
            else
                echo "File not found!"
            fi
            ;;
        3)
            read -p "Enter the file path to update access time: " file_path
            if [ -f "$file_path" ]; then
                touch $file_path
                echo "Access time of $file_path updated to current time."
            else
                echo "File not found!"
            fi
            ;;
        4)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid option"
            ;;
    esac
done
