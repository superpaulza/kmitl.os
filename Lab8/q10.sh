for file in $(find . -type f -name "l*.c")
do
    #trimmedName=`echo $file|cut -d'/' -f2`
    trimmedName=`echo $file | cut -d'/' -f2 | cut -d'.' -f1`
    echo $file $trimmedName
done