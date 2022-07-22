/*
 * Exercise 9 - String Reversal
 * We�ve seen that strings are just arrays of characters. Create a char array and initialize it with any message.
 * The char array should have a size of 30 independently of the size of your string.
 * Output your string and reverse it using a loop and a second char array, then output the reversed string.�
 * Do not hard code the size of your string when looping through it.
 */
#include <iostream>

int main()
{
	char MyArray[42] = "_Seeking vengeance against the dark lords";

	std::cout << MyArray << std::endl;

	const int ArrayLength = (sizeof(MyArray) / sizeof(char));
	int AuxiliarLength = ArrayLength - 1;

	char ArrayReverse[ArrayLength]; // creates a second array with the size of the first

	for (int i = 0; i < ArrayLength; i++)
	{
		if (MyArray[i] == '\0')
		{
			ArrayReverse[AuxiliarLength] = ' ';
		}
		else if (MyArray[i] == '_')
		{
			ArrayReverse[AuxiliarLength] = '\0';
		}
		else
		{
			ArrayReverse[AuxiliarLength] = MyArray[i];
		}
		// std::cout << MyArray[AuxiliarLength] ;
		AuxiliarLength--;
	}

	std::cout << "Arreglo volteao: " << ArrayReverse << std::endl;
}