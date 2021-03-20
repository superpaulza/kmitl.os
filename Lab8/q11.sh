for file in $(find . -type f -name "*.c")
do
    prog_name=`echo $file | cut -d'/' -f2 | cut -d'.' -f1`
    prog_name_input=$(echo $file | cut -d'/' -f2)
    gcc -o $prog_name $prog_name_input &> /dev/null
    if [ -f $prog_name ]
    then
        out=$(./$prog_name)
        if [ $out = "20" ]
        then
            out=10
        else
            out=7
        fi 
    else
        out=5
    fi
    printf "%s\t%s\n" $prog_name_input $out
done