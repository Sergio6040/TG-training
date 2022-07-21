/*
* Exercise 9 - String Reversal
* We’ve seen that strings are just arrays of characters. Create a char array and initialize it with any message. 
* The char array should have a size of 30 independently of the size of your string. 
* Output your string and reverse it using a loop and a second char array, then output the reversed string. 
* Do not hard code the size of your string when looping through it.
*/
#include <iostream>

int main()
{
	char myArray[42] = "_Seeking vengeance against the dark lords";

	
	std::cout << myArray << std::endl;

	const int arrayLength = (sizeof(myArray) / sizeof(char));
	int auxiliarLength = arrayLength-1;

	char arrayVolteao[arrayLength];//creates a second array with the size of the first

	for(int a=0; a < arrayLength; a++)
	{
		if(myArray[a] == '\0')
		{
			arrayVolteao[auxiliarLength] = ' ';
		}
		else if (myArray[a] == '_')
		{
			arrayVolteao[auxiliarLength] = '\0';
		}
		else
		{
			arrayVolteao[auxiliarLength] = myArray[a];
		}
		//std::cout << myArray[auxiliarLength] ;
		auxiliarLength--;
	}

	std::cout << "Arreglo volteao: " << arrayVolteao << std::endl;


}