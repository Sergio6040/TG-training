/*
Exercise 7 - Rock, Paper, Scissors
Write a simple rock, paper, scissors game.
Ask the user for their guess on the result, then tell them whether they guessed right or wrong.

Example output
Welcome to Rock, Paper, Scissors!

1 - Rock
2 - Paper
3 - Scissors
Choose your weapon: 2

Your choice: Paper
Computer’s choice: Rock

You win… big deal!
*/

#include <iostream>

enum option {
	rock = 1, paper, scissors
};

std::string toText(option a) {
	std::string value;
	switch (a) {
		case rock:
			value = "Rock";
			break;
		case paper:
			value = "Paper";
			break;
		case scissors:
			value = "Scissors";
			break;
	}
	return value;
}

int main() {
	while (true) {

		int userChoise;

		std::cout << "Welcome to Rock, Paper, Scissors!" << std::endl;
		std::cout << "1 - Rock\n2 - Paper\n3 - Scissors\n" << std::endl;

		std::cout << "Choose your weapon: ";
		std::cin >> userChoise;

		srand(time(0));

		int pcChoise = 1 + (rand() % 3);
		std::cout << "Your choise: " << toText((option)userChoise) << std::endl;
		std::cout << "Computer's choise: " << toText((option)pcChoise) << std::endl;

		if (userChoise == pcChoise) {
			std::cout << "\nDraw\n" << std::endl;
		}
		else {
			switch (userChoise) {
			case rock:
				if (pcChoise == scissors) {
					std::cout << "\nYou Win!\n" << std::endl;
				}
				else {
					std::cout << "\nYou Loose!\n" << std::endl;
				}
				break;
			case paper:
				if (pcChoise == rock) {
					std::cout << "\nYou Win!\n" << std::endl;
				}
				else {
					std::cout << "\nYou Loose!\n" << std::endl;
				}
				break;
			case scissors:
				if (pcChoise == paper) {
					std::cout << "\nYou Win!\n" << std::endl;
				}
				else {
					std::cout << "\nYou Loose!\n" << std::endl;
				}
				break;
			default:
				std::cout << "\nIncorrect option\n" << std::endl;
				break;
			}
		}
	}

}