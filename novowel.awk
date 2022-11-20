BEGIN { line_count=0} !/[aeiou]/{line_count++; print }
END{
printf "Number of lines which do no contain vowels are %d\n", line_count}


