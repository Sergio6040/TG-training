/*
* Exercise 4 - Printer!
* Create a printer class. This class should allow you to store a string and then output it in different formats. Ask the user to input a string and then show what your printer can do! 
* Remember to use char arrays instead of strings and avoid the std namespace.
*
* You class should have the following methods:
* Printer();
* Printer(std::string outputString);
* void Print();
* void PrintReversed();
* void PrintSpaced(int spaces);
* void PrintVertically();
*/

#include <iostream>

class FPrint
{
public:
	std::string Text;

	FPrint() 
	{
		Text = " ";
	}

	FPrint(std::string outputText) 
	{
		Text = outputText;
		std::cout << Text << std::endl;

		PrintReversed();
		PrintSpaced();
		PrintVertically();
	}

	void PrintReversed()
	{
		int size = Text.length();

		char TextReversed[10];

		for (int i = size - 1; i >= 0; i--)
		{
			TextReversed[size - 1 - i] = Text[i];
		}

		TextReversed[size] = 0;
		std::cout << TextReversed << std::endl;
	}

	void PrintSpaced()
	{
		for (char j : Text)
		{
			std::cout << j << " ";
		}
		std::cout << std::endl;

	}

	void PrintVertically()
	{
		for (char j : Text)
		{
			std::cout << j << std::endl;
		}

	}

};

int main() {
	std::string word;
	std::cout << "Please enter a word: ";
	std::cin >> word;

	std::cout << "---------->Printer<----------" << std::endl;

	FPrint printer = FPrint(word);
}


