#include <stdio.h>

int main(){
int num1, num2, mul;

printf("Enter the first number : ");
scanf("%d",&num1);

printf("Enter the second number : ");
scanf("%d",&num2);

mul = num1 * num2;

printf("%d * %d = %d\n", num1, num2, mul);
return 0;
}
/*
>All the files are in C programming
>To execute them:
	->Locate to the directory where the downloaded file is 
	->If you are using graphics mode then, right click and open the terminal
	->Type the following code:
		gcc "file.c" -0 file
	->Then type:
		./file
	->If you are using command line interface then change directory to the downloaded file
	->Type the following code:
		gcc "file.c" -0 file
	->Then type:
		./file
*/
