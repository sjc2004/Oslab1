while true; do
    clear
    echo "Menu:"
    echo "1. Merge contents of two files"
    echo "2. Search for a pattern in a file"
    echo "3. Exit"
    echo -n "Enter your choice: "
    
    read choice

    case $choice in
        1)
            echo -n  " Enter the first file name: "
            read file1
            echo -n "Enter the second file name: "
            read file2
            echo -n "Enter the output file name: "
            read output_file

            if [ -f "$file1" ] && [ -f "$file2" ]; then
                cat "$file1" "$file2" > "$output_file"
                echo "Merged contents of $file1 and $file2 into $output_file"
            else
                echo "One or both input files do not exist."
            fi
            ;;
        2)
            echo -n "Enter the file name to search in: "
            read search_file
            echo -n "Enter the pattern to search: "
            read pattern

            if [ -f "$search_file" ]; then
                grep "$pattern" "$search_file"
            else
                echo "The input file does not exist."
            fi
            ;;
        3)
            echo "Exiting the script."
            exit 0
            ;;
        *)
            echo "Invalid option. Please select a valid option from the menu."
            ;;
    esac

    echo -n "Press Enter to continue..."
    read -r
done

