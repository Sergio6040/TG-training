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
	int LotteryArraySize = sizeof(Lottery) / sizeof(int);
	for (int i = 0; i < LotteryArraySize; i++)
	{
		//populate the Lottery array
		int RandomNumber = 1 + rand() % 20;
		bool bIsRandomRepeated = false;

		for (int LotteryNumber : Lottery)
		{
			if (LotteryNumber == RandomNumber)
			{
				bIsRandomRepeated = true;
				i--;
			}
		}

		if (!bIsRandomRepeated)
		{
			Lottery[i] = RandomNumber;
		}
	}

	int Index = 0;
	while (Index < LotteryArraySize)
	{
		int UserInput;
		bool bIsRepeated = false;
		std::cout << "Enter your guess between [1, 20]: ";
		std::cin >> UserInput;

		//checks if the number is repeated
		for (int GuessNumber : UserGuess)
		{
			if (GuessNumber == UserInput)
			{
				bIsRepeated = true;
				std::cout << "Do not repeat numbers!" << std::endl;
			}
		}

		//checks the rage of numbers and stores the value
		if ((UserInput >= 1 && UserInput <= 20) && !bIsRepeated)
		{

			UserGuess[Index] = UserInput;
			Index++;
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

	for (int LotteryNumber : Lottery) 
	{
		for (int GuessNumber : UserGuess)
		{
			if (LotteryNumber == GuessNumber)
			{
				Jackpot += 10;
			}
		}
		std::cout << LotteryNumber << " ";
	}

	std::cout << "\nYour prize: " << Jackpot << " $" << std::endl;

}