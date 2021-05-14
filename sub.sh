#!/bin/bash
#To run the code:
#step1 -> change mode of the file on terminal 
#chmod u+x sub.sh
#step2 -> ./sub.sh

echo -n "Enter the first number : "
read num1
echo -n "Enter the second number : "
read num2
sub=`expr $num1 - $num2`

echo "$num1 - $num2 = $sub"


