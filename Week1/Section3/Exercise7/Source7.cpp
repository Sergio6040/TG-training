/*
 * Exercise 7 - Lottery
 * Write a program that will simulate the Lottery. Create two arrays of 5 integers.
 * The first array should be populated with 5 random numbers from 1-20. For the second array, ask the user to input 5 numbers from 1-20.
 * Make sure to handle invalid input and make sure numbers are not repeated.
 * For each number that is matched in the same index, give the user $10.
 */

#include <iostream>

bool IsNumberRepeated(int ArrayToCheck[5], int Number)
{
	for (int i = 0; i < 5; i++)
	{
		if (ArrayToCheck[i] == Number)
		{
			std::cout << "Do not repeat numbers!" << std::endl;
			return true;
		}
	}
	return false;
}

int main()
{
	int Lottery[5];
	int UserGuess[5];

	std::cout << "-----> Welcome to the Teravision Lottery <-----\n"
			  << "   	may the luck be with you!" << std::endl;

	/* initialize random seed: */
	srand(time(NULL));

	int LotteryArraySize = sizeof(Lottery) / sizeof(int);

	for (int i = 0; i < LotteryArraySize; i++)
	{
		// populate the Lottery array
		int RandomNumber = 1 + rand() % 20;
		bool bIsRandomRepeated = false;

		bIsRandomRepeated = IsNumberRepeated(Lottery, RandomNumber);

		if (bIsRandomRepeated)
		{
			//moves back 1 position to not leave gaps in the array
			i--;
		}
		else
		{
			Lottery[i] = RandomNumber;
		}
	}

	int index = 0;
	while (index < LotteryArraySize)
	{
		int UserInput;
		bool bIsRepeated = false;
		std::cout << "Enter your guess between [1, 20]: ";
		std::cin >> UserInput;

		bIsRepeated = IsNumberRepeated(UserGuess, UserInput);

		// checks the rage of numbers and stores the value
		if ((UserInput >= 1 && UserInput <= 20) && !bIsRepeated)
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

	for (int i = 0; i < LotteryArraySize; i++)
	{
		if (Lottery[i] == UserGuess[i])
		{
			Jackpot += 10;
		}
		std::cout << Lottery[i] << " ";
	}

	std::cout << "\nYour prize: " << Jackpot << " $" << std::endl;
}