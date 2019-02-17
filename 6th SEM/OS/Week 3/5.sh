#!/bin/sh

echo "     ----Marksheet----"
read -p "Enter the marks of the student: " m
echo " "

if [ $m -le 100 -a $m -ge 90 ]
then
    grade="A"
elif [ $m -le 89 -a $m -ge 70 ]
then
    grade="B"
elif [ $m -le 69 -a $m -ge 40 ]
then
    grade="C"
else
    grade="F"
fi

echo "Grade given: $grade \n\n"
