read -p "Enter The Number: "  n
for((i=0; i<$n; i++))
do
read -p "Enter value of arr[$i]: " arr[$i]
done
#sorting code
for((i=0; i<$n; i++))
do
for((j=0; j<n-i-1; j++))
do
if [ ${arr[j]} -lt ${arr[$((j+1))]} ]
then
#swapping
temp=${arr[j]}
arr[$j]=${arr[$((j+1))]}
arr[$((j+1))]=$temp
fi
done
done
echo "Numbers in Descending order:  ${arr[*]}"
