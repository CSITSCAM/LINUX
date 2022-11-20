# !/bin/bash
echo "enter a number"
read num
n=$num
fact=1
while [ $num -ge 1 ]
do
fact=$((fact*num))
num=$((num-1))
done
echo "factorial of $n is $fact"
