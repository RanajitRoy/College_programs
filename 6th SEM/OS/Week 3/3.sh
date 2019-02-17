#!/bin/sh

echo "Enter: "
echo -n "a = "
read a
echo -n "b = "
read b
c=$a
a=$b
b=$c
echo "Value of \na = $a \nb = $b"
