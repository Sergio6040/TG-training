/*
 * Exercise 7 - Lottery
 * Write a program that will simulate the Lottery. Create two arrays of 5 integers.
 * The first array should be populated with 5 random numbers from 1-20. For the second array, ask the user to input 5 numbers from 1-20.
 * Make sure to handle invalid input and make sure numbers are not repeated.
 * For each number that is matched in the same index, give the user $10.
 */

#include <iostream>

int main()
{
	int Lottery[5];
	int UserGuess[5];

	std::cout << "-----> Welcome to the Teravision Lottery <-----\n"
			  << "   	may the luck be with you!" << std::endl;

	/* initialize random seed: */
	srand(time(NULL));

	for (int i = 0; i < sizeof(Lottery) / sizeof(int); i++)
	{
		// populate the Lottery array
		int RandomNumber = 1 + rand() % 20;
		bool isRandomRepeated = false;

		for (int x : Lottery)
		{
			if (x == RandomNumber)
			{
				isRandomRepeated = true;
				i--;
			}
		}

		if (!isRandomRepeated)
		{
			Lottery[i] = RandomNumber;
		}
	}

	int index = 0;
	while (index < (sizeof(Lottery) / sizeof(int)))
	{
		int UserInput;
		bool isRepeated = false;
		std::cout << "Enter your guess between [1, 20]: ";
		std::cin >> UserInput;

		// checks if the number is repeated
		for (int x : UserGuess)
		{
			if (x == UserInput)
			{
				isRepeated = true;
				std::cout << "Do not repeat numbers!" << std::endl;
			}
		}

		// checks the rage of numbers and stores the value
		if ((UserInput >= 1 && UserInput <= 20) && !isRepeated)
		{

			UserGuess[index] = UserInput;
			index++;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Wrong input!" << std::endl;
		}
	}

	int Jackpot = 0;
	std::cout << "\nLottery Result: ";

	for (int i = 0; i < (sizeof(Lottery) / sizeof(int)); i++)
	{
		if (Lottery[i] == UserGuess[i])
		{
			Jackpot += 10;
		}
		std::cout << Lottery[i] << " ";
	}

	std::cout << "\nYour prize: " << Jackpot << " $" << std::endl;
}