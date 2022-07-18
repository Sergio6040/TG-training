/*
* Exercise 10 - Anything but Lowercase Vowel
Rewrite the previous exercise but this time check that the given character is NOT a lowercase vowel. Use the same conditions you used previously and only change the relational operators. You are not allowed to use a negation operator to wrap the whole set of conditions.
Hint: You might want to look up DeMorgan’s Law for this one.

Example output
Hello! Please enter an alphabetical character: c
Your character is not a lowercase vowel.
*/

#include <iostream>

int main() {
	char letter;
	std::cout << "Hello! Please enter an alphabetical character: ";
	std::cin >> letter;

	if (!islower(letter) && (letter != 'a' && letter != 'e' && letter != 'i' && letter != 'o' && letter != 'u')) {
		std::cout << "Your character is an UPPERCASE vowel! :)" << std::endl;
	}
	else {
		std::cout << "Your character is not an UPPERCASE vowel! :(" << std::endl;
	}
}