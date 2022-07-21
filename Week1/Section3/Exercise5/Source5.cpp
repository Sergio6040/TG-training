/*
* Exercise 5 - Arrays
* Create an array of whatever size you want. Let the user input as many numbers as they want and populate the array with them. 
* If they enter any invalid input, output the whole array of numbers and the Sum of them all and the total numbers they input.
* If the user exceeds the size of your array, tell them about it and then output the information.
*/

#include <iostream>

int main()
{
	int MyArray[8] = {0, 0, 0, 0, 0, 0, 0, 0};//if is not initialized it will put the value of INT_MIN
	int EnteredNumbers = 0;


	
	while (true)
	{
		if (EnteredNumbers >= sizeof(MyArray) / sizeof(int))
		{
			std::cout << "you try exceed the length of the array!" << std::endl;
			break;
		}
		std::cout << "Please enter a number: ";
		std::cin >> MyArray[EnteredNumbers];

		if (std::cin.fail() || std::cin.bad()) 
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Wrong input!\n";
			break;
		}

		EnteredNumbers++;
	}


	int Sum = 0;
	std::cout << "numbers entered: [";
	for (int x : MyArray)
	{
		std::cout  << x << " ";
		Sum += x;
	}

	std::cout << "]" << std::endl;
	std::cout << "The Sum of your numbers is: " << Sum << std::endl;
	std::cout << "You entered " << EnteredNumbers << " number(s)" << std::endl;
	
}