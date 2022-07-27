/*
* Exercise 1 - Input Validation
* Write a program that will ask the user to enter a number between 1-10. 
* Keep asking the same question until a valid input is given. Add an annoyed comment if they take more than a certain number of tries.
*/

#include <iostream>

int main()
{
	int UserInput;
	int LoopCounter = 0;
	
	do
	{
		std::cout << "Please enter a number between 1 - 10 : ";
		std::cin >> UserInput;

		LoopCounter++;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Wrong input!\n";
		}
	}
	while (UserInput < 1 || UserInput > 10);

	if (LoopCounter < 3) 
	{
		std::cout << "Great, correct number!" << std::endl;
	}
	else
	{
		std::cout << "Finally! Was that hard?? maybe this is too advance for you." << std::endl;
	}
}