echo -e "\nPresent Working Directory: `pwd`\n\n"

read -p "Enter the number: " n
a=`expr $n % 2`
if [ n == 0 ]
then
    echo -e "$a is Even\n\n"
else
    echo -e "$a is Odd\n\n"
fi

a=`ls -p | grep -v "/$" | wc -w`
echo -e "Count of All the files: $a\n\n"

echo -e "Long listing of all files in current directory:"
ls -l -p | grep -v "/$"
echo -e "\n"