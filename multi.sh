#!/bin/bash
#To run the code:
#step1 -> change mode of the file on terminal 
#chmod u+x multi.sh
#step2 -> ./multi.sh

echo -n "Enter the first number : "
read num1
echo -n "Enter the second number : "
read num2
mul=$((num1 * num2))

echo "$num1 * $num2 = $mul"


