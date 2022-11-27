BEGIN{total_len=0}
{
len=length($0)
total_len+=len
words+=NF
}
END{
printf "Total no.of characters=%d\n", total_len
printf "Total no.of words=%d\n",words
printf "Total no.of lines=%d\n",NR
}
