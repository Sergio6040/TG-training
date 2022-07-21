/*
* Exercise 8 - Easier Lottery
* Rewrite the previous Lottery but now instead of getting $10 for each number matched in the exact same index, give the user $10 for any number that matches anywhere in the sequence.
*/


#include <iostream>

int main()
{
	int Lottery[5];
	int UserGuess[5];

	std::cout << "-----> Welcome to the Teravision Lottery <-----\n" << "   	may the luck be with you!" << std::endl;

	/* initialize random seed: */
	srand(time(NULL));

	for (int i = 0; i < sizeof(Lottery) / sizeof(int); i++)
	{
		//populate the Lottery array
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

	//trampa----------------------------------------------------------------------------------------------------
	for (int a : Lottery)
	{
		std::cout << a << " ";
	}

	int index = 0;
	while (index < (sizeof(Lottery) / sizeof(int)))
	{
		int UserInput;
		bool isRepeated = false;
		std::cout << "Enter your guess between [1, 20]: ";
		std::cin >> UserInput;

		//checks if the number is repeated
		for (int x : UserGuess)
		{
			if (x == UserInput)
			{
				isRepeated = true;
				std::cout << "Do not repeat numbers!" << std::endl;
			}
		}

		//checks the rage of numbers and stores the value
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

	for (int a : Lottery) 
	{
		for (int b : UserGuess)
		{
			if (a == b)
			{
				Jackpot += 10;
			}
		}
		std::cout << a << " ";
	}

	std::cout << "\nYour prize: " << Jackpot << " $" << std::endl;

}