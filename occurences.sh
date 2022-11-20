if [ $# -ne 2 ]
then
echo "Error: Invalid number of arguments."
exit
fi
str=`cat $1 | tr '\n' ' '`
for a in $str
do
echo "Word = $a, Count = `grep -c "$a" $2`"
done
