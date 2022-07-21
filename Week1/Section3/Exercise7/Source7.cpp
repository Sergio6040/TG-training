/*
* Exercise 7 - Lottery
* Write a program that will simulate the lottery. Create two arrays of 5 integers. 
* The first array should be populated with 5 random numbers from 1-20. For the second array, ask the user to input 5 numbers from 1-20.
* Make sure to handle invalid input and make sure numbers are not repeated.
* For each number that is matched in the same index, give the user $10.
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

	int index = 0;
	while (index < (sizeof(lottery) / sizeof(int)) )
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
	
	for (int i = 0; i < (sizeof(lottery) / sizeof(int)) ; i++)
	{
		if (lottery[i] == userGuess[i])
		{
			jackpot += 10;
		}
		std::cout << lottery[i] << " ";
	}

	std::cout << "\nYour prize: " << jackpot << " $" << std::endl;

}