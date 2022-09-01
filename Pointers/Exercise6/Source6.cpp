/*
* Exercise 6 - Pointer Arithmetic
* Pointer arithmetic allows you to perform arithmetic operations on pointer types.
* Create a program where you declare an array of 10 integers. Then, declare an int pointer and
* initialize it to the array.
*
* Loop through all of the elements in the array and initialize each entry in the array with a random
* integer. You must use ONLY the pointer to loop through the array. Print each number to the
* console.
* Then, loop through the array BACKWARDS to get the sum of all the elements. Print the sum to
* the console.
* Example output
* I’ve looped through the following numbers:
* 10 15 63 52 19 99 105 11 11 16
* The sum of all those numbers is 401
*/

#include <stdlib.h> 
#include <iostream>

#define Print(Text) (std::cout << Text << std::endl)

int main()
{
	srand(NULL);

	int NumberArray[10];
	int ArrayLength = sizeof(NumberArray) / sizeof(sizeof(NumberArray) / sizeof(*NumberArray));
	int* ArrayPtr = NumberArray;

	for (int* i = ArrayPtr; i != (ArrayPtr + ArrayLength); i++)
	{
		int Random{rand() % 50};
		std::cout << Random << ", ";
		*i = Random;
	}
	Print("");

	int Sum{0};
	for (int* i = ArrayPtr + ArrayLength - 1; i != (ArrayPtr - 1); i--)
	{
		Sum += *i;
	}
	Print("The sum of all those numbers is: " << Sum);
}