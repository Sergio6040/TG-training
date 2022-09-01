 /*
* Exercise 1 - Understanding Memory Addresses
* Create a program that will ask the user to enter an integer and assign the given value to a
* variable. Then, print the value to the console, and print the memory address of that variable.
* Then, ask for another value and assign that value to the same variable. Print the value and the
* memory address to the console.
* Finally, ask for one more value. This time, assign the value to a different variable. Print the
* value and the memory address to the console. Do the results make sense to you?
 */

#include <iostream>

int ValidateInput()
{
	int InputNumber;
	while (true)
	{
		std::cin >> InputNumber;

		if (std::cin.good())
		{
			return InputNumber;
		}

		std::cin.clear();
		std::cin.ignore(100 ,'\n');
		std::cout << "Try Again >>";
	}
	
}

int main()
{
	std::cout << "enter a number: ";
	int InputNumber = ValidateInput();
	int* InputPtr = &InputNumber;
	std::cout << InputNumber << " -> " << InputPtr << std::endl;

	std::cout << "enter another number: ";
	InputNumber = ValidateInput();
	std::cout << InputNumber << " -> " << InputPtr << std::endl;

	std::cout << "enter a number: ";
	int SecondInputNumber = ValidateInput();
	InputPtr = &SecondInputNumber;
	std::cout << SecondInputNumber << " -> " << InputPtr << std::endl;
}

