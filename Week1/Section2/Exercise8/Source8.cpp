/*
* Exercise 8 - Magic 8 Ball
Write a program that will predict the future for the user. Tell them to ask a question and then create a prediction for them. Make sure to use an enum and a switch statement for this exercise

Example output
Welcome to your future! Ask a question: Will I ever be loved?
Your answer is: Hmmm… perhaps!
*/
#include <iostream>

enum answers{
	yes, no, probabbly, never, maybe, absolutly

};

int main() {
	std::string userAnswer;

	std::cout << "Hello! I'm Zoltron, ask me something and I will tell you your fate!" << std::endl;
	std::cout << ">>";
	std::cin >> userAnswer;

	int fate = (rand() % 5);

	switch (fate){
		case yes:
			std::cout << "your'r lucky, the answer is yes!" << std::endl;
			break;
		case no:
			std::cout << "No way!" << std::endl;
			break;
		case probabbly:
			std::cout << "the numbers are at your favor!" << std::endl;
			break;
		case never:
			std::cout << "In any posible Future!" << std::endl;
			break;
		case maybe:
			std::cout << "maybe, if you go big or go home!" << std::endl;
			break;
		case absolutly:
			std::cout << "take it for granted!" << std::endl;
			break;
	default:
		std::cout << "Incalculable" << std::endl;
		break;
	}
}