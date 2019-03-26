echo -e "\n\t----Prime Numbers between 1 to 100----\n"

for x in `seq 2 100`
do
    count=0
    u=`echo "sqrt($x)" | bc`
    for y in `seq 1 $u`
    do
        mod=`expr $x % $y`
        if [ $mod == 0 ]
        then
            count=`expr $count + 1`
        fi
    done
    if [ $count -lt 2 ]
    then
        echo -n "$x, "
    fi
done
echo -e "\n"