/*
* Exercise 2 - Understanding Pointers
* Create a program that will ask the user for an integer value. Assign the value to an integer
* variable.
* Then, create an int* variable and assign it to the memory address of the integer variable.
* Ask the user to enter a new value for the variable. Then, using only the pointer variable, change
* the value of the integer variable to the new value.
* Print the resulting value of variable a.
*/
#include <iostream>

int main()
{
	std::cout << "enter a number: ";
	int InputNumber;
	std::cin >> InputNumber;
	int* InputNumberPtr = &InputNumber;
	std::cout << InputNumber << " -> " << InputNumberPtr << std::endl;


	std::cout << "enter another number: ";
	std::cin >> *InputNumberPtr;
	std::cout << InputNumber << " -> " << InputNumberPtr << std::endl;
}