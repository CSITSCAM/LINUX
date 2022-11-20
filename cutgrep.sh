echo "Enter filename: "
read fname
echo "Displaying only the first word of each lines"
cut -d " " -f 1 $fname
echo "Displaying lines in the file with the word - the:"
grep -i "the" $fname
echo "Displaying head of the file: "
head $fname
echo "Displaying tail of the file: "
tail $fname
echo "Using more command to read contents of the file: "
more $fname
