/*
 * Exercise 1 - Useless Program
 * Create an integer that will instantiate an integer to the heap and assign
 * it whatever value you like. Print the value of the integer and the
 * memory address of that int. done with the delete keyword. Make sure to free
 * the memory you allocated for your int before exiting the program. Example
 * output I’ve dynamically allocated an integer. Its value is 56 and its memory
 * address is 0x7ffd46bfb370
 */

#include <iostream>

#define Print(Text) std::cout << Text << std::endl;

int main()
{
	int* Number = new int{5};
	Print("I've dynamically allocated an integer.");
	Print("number " << *Number << " at " << Number);
	delete Number;
}