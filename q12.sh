# Generate all possible combinations of 3 numbers
for num1 in {1..9}; do
    for num2 in {1..9}; do
        for num3 in {1..9}; do
            if [ $num1 -ne $num2 ] && [ $num1 -ne $num3 ] && [ $num2 -ne $num3 ]; then
                echo "$num1 $num2 $num3"
            fi
        done
    done
done
