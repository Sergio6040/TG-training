/*
* Exercise 3 - Understanding Pointers 2
*
* Create a program that will ask the user to enter two integers and assign the given values to two
* separate integers.
* Declare an int* variable and assign it to the memory address of the first integer. Now, using only
* the pointer variable, print the value of the first integer and its memory address. Additionally, print
* the value and the memory address of the pointer variable.
* 
* Then, assign the memory address of the second integer to the same pointer variable. Do the
* same thing as before: using only the pointer variable, print the value of the integer, its memory
* address, and the value and memory address of the pointer variable.
* Do the results make sense to you?
*/

#include <iostream>

int main()
{
	int FirstNumber;
	int SecondNumber;

	std::cout << "Please enter a value for variable A: ";
	std::cin >> FirstNumber;
	std::cout << "Please enter a value for variable B: ";
	std::cin >> SecondNumber;

	int* Address = &FirstNumber;

	std::cout << "\nUsing pointer variable P, I've determined that :" << std::endl;
	std::cout << "The value of A is: " << *Address << std::endl;
	std::cout << "at: " << Address << std::endl;
	std::cout << "The value of P is: " << Address << std::endl;
	std::cout << "at: " << &Address << std::endl;

	Address = &SecondNumber;

	std::cout << "\nUsing the same pointer variable P, I've also determined that :" << std::endl;
	std::cout << "The value of B is: " << *Address << std::endl;
	std::cout << "at: " << Address << std::endl;
	std::cout << "The value of P is: " << Address << std::endl;
	std::cout << "at: " << &Address << std::endl;

}