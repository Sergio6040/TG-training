#include <iostream>

#define Print(Text) std::cout << Text << std::endl;


float GetValidateInput(int Min, int Max, std::string Message)
{
	int UserInput;
	while (true)
	{
		Print(Message);
		std::cin >> UserInput;

		if (UserInput >= Min && UserInput <= Max && std::cin.good())
		{
			return UserInput;
		}
		std::cin.clear();
		std::cin.ignore(100, '\n');
		system("cls");
	}
}

float GetValidateInput(std::string Message)
{
	int UserInput;
	while (true)
	{
		Print(Message);
		std::cin >> UserInput;

		if (std::cin.good())
		{
			return UserInput;
		}
		std::cin.clear();
		std::cin.ignore(100, '\n');
		system("cls");
	}
}