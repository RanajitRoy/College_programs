echo -e "\n\t----Pattern----\n"

for i in `seq 1 4`
do
    echo -ne "\t"
    for j in `seq 1 $i`
    do
        echo -n "*"
    done
    echo -e "\n"
done


