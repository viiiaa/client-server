#!/bin/bash
#To run the code:
#step1 -> change mode of the file on terminal
#chmod u+x add.sh
#step2 -> ./add.sh
echo -n "Enter the first number : "
read num1
echo -n "Enter the second number : "
read num2
sum=`expr $num1 + $num2`

echo "$num1 + $num2 = $sum"
