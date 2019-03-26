echo -e "\n\t----Factorial of a Number----\n"
read -p "Enter the number: " n

res=1

for x in `seq 1 $n`
do
    res=`expr $res \* $x`
done

echo -e "\nFactorial of $n :  $res\n\n"