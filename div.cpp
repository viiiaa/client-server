#include <iostream>
using namespace std;

int main()
{
    int num1,num2,divide;
    cout<<"Enter the first number : ";
    cin>>num1;

    cout<<"Enter the second number : ";
    cin>>num2;

    divide = num1 / num2;
    cout<< num1 << " + " << num2 << " = "<< divide << endl;

    return 0;
}

/*
>All the files are in C++ programming
>To execute them:
	->Locate to the directory where the downloaded file is 
	->If you are using graphics mode then, right click and open the terminal
	->Type the following code:
		gcc "file.cpp" -0 file
	->Then type:
		./file
->If you are using command line interface then change directory to the downloaded file
	->Type the following code:
		gcc "file.cpp" -0 file
	->Then type:
		./file
*/
