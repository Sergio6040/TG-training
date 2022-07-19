/*
* Exercise 9 - Lowercase Vowel
Write a program that will receive an alphabetical character from the user. Then, tell them if the character is a lowercase vowel. Make sure to do this using a single if statement.

Example output
Hello! Please enter an alphabetical character: c
Your character is not a lowercase vowel.
*/

#include <iostream>

int main() {
	char letter;
	std::cout << "Hello! Please enter an alphabetical character: ";
	std::cin >> letter;

	if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
		std::cout << "Your character is a lowercase vowel! :)" << std::endl;
	}else{
		std::cout << "Your character is not a lowercase vowel! :(" << std::endl;
	}
}