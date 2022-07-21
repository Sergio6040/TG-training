/*
* Exercise 8 - Easier Lottery
* Rewrite the previous lottery but now instead of getting $10 for each number matched in the exact same index, give the user $10 for any number that matches anywhere in the sequence.
*/


#include <iostream>

int main()
{
	int lottery[5];
	int userGuess[5];

	std::cout << "-----> Welcome to the Teravision Lottery <-----\n" << "   	may the luck be with you!" << std::endl;

	/* initialize random seed: */
	srand(time(NULL));

	for (int i = 0; i < sizeof(lottery) / sizeof(int); i++)
	{
		//populate the lottery array
		int randomNumber = 1 + rand() % 20;
		bool isRandomRepeated = false;

		for (int x : lottery)
		{
			if (x == randomNumber)
			{
				isRandomRepeated = true;
				i--;
			}
		}

		if (!isRandomRepeated)
		{
			lottery[i] = randomNumber;
		}
	}

	//trampa----------------------------------------------------------------------------------------------------
	for (int a : lottery)
	{
		std::cout << a << " ";
	}

	int index = 0;
	while (index < (sizeof(lottery) / sizeof(int)))
	{
		int userInput;
		bool isRepeated = false;
		std::cout << "Enter your guess between [1, 20]: ";
		std::cin >> userInput;

		//checks if the number is repeated
		for (int x : userGuess)
		{
			if (x == userInput)
			{
				isRepeated = true;
				std::cout << "Do not repeat numbers!" << std::endl;
			}
		}

		//checks the rage of numbers and stores the value
		if ((userInput >= 1 && userInput <= 20) && !isRepeated)
		{

			userGuess[index] = userInput;
			index++;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Wrong input!" << std::endl;
		}
	}

	int jackpot = 0;
	std::cout << "\nLottery Result: ";

	for (int a : lottery) 
	{
		for (int b : userGuess)
		{
			if (a == b)
			{
				jackpot += 10;
			}
		}
		std::cout << a << " ";
	}

	std::cout << "\nYour prize: " << jackpot << " $" << std::endl;

}