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

	char ArrayVolteao[ArrayLength]; // creates a second array with the size of the first

	for (int a = 0; a < ArrayLength; a++)
	{
		if (MyArray[a] == '\0')
		{
			ArrayVolteao[AuxiliarLength] = ' ';
		}
		else if (MyArray[a] == '_')
		{
			ArrayVolteao[AuxiliarLength] = '\0';
		}
		else
		{
			ArrayVolteao[AuxiliarLength] = MyArray[a];
		}
		// std::cout << MyArray[AuxiliarLength] ;
		AuxiliarLength--;
	}

	std::cout << "Arreglo volteao: " << ArrayVolteao << std::endl;
}