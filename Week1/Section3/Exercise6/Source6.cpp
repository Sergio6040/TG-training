/*
 * Exercise 6 - Arrays improved!
 * Rewrite the previous exercise, but this time only exit the application if the user inputs the ENTER key or when they exceed the max amount of numbers.
 * If the user enters any invalid input, tell them that they�ve entered an invalid input and that they must enter a number.
 * If the user just hits ENTER when asked for a number, output the same information as the previous exercise.�
 * Hint: You�ll need to look up stuff here, too. How would you detect invalid input and an enter key press?
 */

#include <iostream>
#include <conio.h>

int main()
{
	int MyArray[8] = {0, 0, 0, 0, 0, 0, 0, 0}; // if is not initialized it will put the value of INT_MIN
	int EnteredNumbers = 0;

	std::cout << "---- Press ENTER whenever you want to finish ----\n" << std::endl;

	while (true)
	{
		if (EnteredNumbers >= sizeof(MyArray) / sizeof(int))
		{
			std::cout << "you try exceed the length of the array!" << std::endl;
			break;
		}

		std::cout << "Please enter a number: ";
		if (std::cin.peek() == '\n') break;
		std::cin >> MyArray[EnteredNumbers];

		if (std::cin.fail() || std::cin.bad())
		{
			std::cin.clear();
			std::cout << "Wrong input! please enter a number or press ENTER to finish.\n";
		}
		else
		{
			EnteredNumbers++;
		}
		
		std::cin.ignore(1000, '\n');
	}

	int Sum = 0;
	std::cout << "numbers entered: [";
	for (int x : MyArray)
	{
		std::cout << x << " ";
		Sum += x;
	}

	std::cout << "]" << std::endl;
	std::cout << "The Sum of your numbers is: " << Sum << std::endl;
	std::cout << "You entered " << EnteredNumbers << " number(s)" << std::endl;
}