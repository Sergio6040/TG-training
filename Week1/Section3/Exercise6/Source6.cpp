/*
 * Exercise 6 - Arrays improved!
 * Rewrite the previous exercise, but this time only exit the application if the user inputs the ENTER key or when they exceed the max amount of numbers.
 * If the user enters any invalid input, tell them that they�ve entered an invalid input and that they must enter a number.
 * If the user just hits ENTER when asked for a number, output the same information as the previous exercise.�
 * Hint: You�ll need to look up stuff here, too. How would you detect invalid input and an enter key press?
 */

#include <iostream>

int main()
{
	int EnteredNumbers[8] = {0, 0, 0, 0, 0, 0, 0, 0}; // if is not initialized it will put the value of INT_MIN
	int Index = 0;

	std::cout << "---- Press ENTER whenever you want to finish ----\n" << std::endl;

	while (true)
	{
		if (Index >= sizeof(EnteredNumbers) / sizeof(int))
		{
			std::cout << "you try exceed the length of the array!" << std::endl;
			break;
		}

		std::cout << "Please enter a number: ";
		if (std::cin.peek() == '\n')
		{
			break;
		}
		std::cin >> EnteredNumbers[Index];

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Wrong input! please enter a number or press ENTER to finish.\n";
		}
		else
		{
			Index++;
		}
		
		std::cin.ignore(1000, '\n');
	}

	int Sum = 0;
	std::cout << "numbers entered: [";
	for (int Number : EnteredNumbers)
	{
		std::cout << Number << " ";
		Sum += Number;
	}

	std::cout << "]" << std::endl;
	std::cout << "The Sum of your numbers is: " << Sum << std::endl;
	std::cout << "You entered " << Index << " number(s)" << std::endl;
}