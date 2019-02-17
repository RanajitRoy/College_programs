#!/bin/sh

if [ $1 -gt $2 ]
then
    if [ $1 -gt $3 ]
    then
        echo "1st argument: $1 is greatest"
    else
        echo "3rd argument: $3 is greatest"
    fi
else
    if [ $2 -gt $3 ]
    then
        echo "2nd argument: $2 is greatest"
    else
        echo "3rd argument: $3 is greatest"
    fi
fi
