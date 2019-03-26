echo -e "\n\t----Chencking Vowel----\n"

read -p "Enter a letter: " letter

vowels="a e i o u A E I O U"
con=`echo $vowels | grep -c $letter`

if [ $con == 1 ]
then
    echo -e "\n$letter is a Vowel\n\n"
else
    echo -e "\n$letter is a Consonent\n\n"
fi
