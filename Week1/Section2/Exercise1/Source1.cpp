/*
Exercise 1 - Age Condition
Write a simple game menu that will ask the user about their age.
Let them enter the game if their age is appropriate, but tell them they can’t enter otherwise.
Example output
Welcome to the game!
WARNING! This game is extremely gory, bloody, and gross. you need to be at least 18 years old to enter.

Please enter your age: 19
Good! You can play the game! But I lied… there is no game :(
*/

#include <iostream>

int main() {

	std::cout << "	In the first age, in the first battle, when the shadows first lengthened, one stood." << std::endl;
	std::cout << "	He chose the path of perpetual torment." << std::endl;
	std::cout << "	In his ravenous hatred he found no peace." << std::endl;
	std::cout << "	And with boiling blood he scoured the Umbral Plains seeking vengeance against the dark lords who had wronged him" << std::endl;
	std::cout << "	And those that tasted the bite of his sword named him...\n" << std::endl;
	std::cout << "	The Doom Slayer." << std::endl;

	int age;
	std::cout << "\nWARNING! This game is extremely gory, bloody, and gross. you need to be at least 18 years old to enter." << std::endl;
	std::cout << "\n>>Whats your age? :";
	std::cin >> age;

	if (age >= 18) {
		std::cout << "You are ready to face mayhem!" << std::endl;
	}
	else {
		std::cout << "You are not old enough, go and cry with your mama!" << std::endl;
	}
}