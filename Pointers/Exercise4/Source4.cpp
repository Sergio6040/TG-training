/*
* Exercise 4 - Understanding Pointers 3
* Create a program where you declare an int variable and initialize it to whatever value you want.
* Print the value to the console.
* Then, create two int pointer variables that point to the variable you just created.
* Dereference the first pointer and add one to the dereferenced value. Do the same thing with the
* second pointer. Print the final value of your initial variable. Do these results make sense to you?
* 
* Example output
* The value of my variable is 5.
* The value of my variable after the pointer stuff I did is 7.
*/
#include <iostream>

int main()
{
	int MyNumber{ 33 };

	std::cout << "The value of my variable is: " << MyNumber << std::endl;

	int* FirstPointer = &MyNumber;
	int* SecondPointer = &MyNumber;

	*FirstPointer = 65;
	*FirstPointer += 1;

	*FirstPointer = MyNumber + 32;
	*FirstPointer += 1;

	std::cout << "The value of my variable after the pointer stuff I did is: " << MyNumber << std::endl;

}