/*
Exercise 3 - Positive, Negative, or Zero
Write a program that will ask the user for a number and determine if it is a positive number, a negative number, or zero.

Example output
Please enter a number: 5

Your number is positive!
*/
#include <iostream>

int main() {
	int value;

	std::cout << "Please enter a number: ";
	std::cin >> value;

	if (value == 0) 
	{
		std::cout << "Your number is Zero" << std::endl;
	}
	else if (value > 0)
	{
		std::cout << "Your number is Positive" << std::endl;
	}
	else
	{
		std::cout << "Your number is Negative" << std::endl;
	}
}