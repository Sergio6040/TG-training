/*
 * Exercise 3 - Multiples of 10
 * Write a program that will output multiples of 10 between 1 and 100. Use a for-loop that goes through numbers 1-100.
 * At the end of the program, output the sum of all the numbers that were NOT multiples of 10.
 * Do NOT use an else statement for this program and do NOT use more than one loop.
 */

#include <iostream>

int main()
{
	int TotalSum = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 10 == 0)
		{
			std::cout << i << ", ";
		}

		if (i % 10 != 0)
		{
			TotalSum += i;
		}
	}

	std::cout << "\nSum of the rest of the numbers: " << TotalSum << std::endl;
}