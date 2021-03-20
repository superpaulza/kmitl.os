# cut and $()
prog_name=$(echo $1 | cut -d'.' -f1)
#printf "%s "
gcc -o $prog_name $1
if [ -f $prog_name ]
then 
    ans=$(./$prog_name)
else
    ans=5
fi
printf "%s %s\n" $1 $ans

# better technique extract file name
# https://stackoverflow.com/questions/965053/extract-filename-and-extension-in-bash