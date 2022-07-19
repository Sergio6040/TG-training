/*
* Exercise 2 - More Input Validation
* Rewrite the true or false quiz you did in the previous section. 
* This time, instead of asking for 1 or 2 as inputs, ask them to answer T or F. 
* If they enter invalid input, give them a couple of tries before you automatically fail them.
*/

#include <iostream>

void makeQuestion(std::string question, bool correctAnswer) {
	bool bUserAnswer = !correctAnswer; 
	int attempts = 0;
	while (bUserAnswer != correctAnswer)
	{
		attempts++;

		if (attempts > 3)
		{
			std::cout << "Number of attempts exceeded, the quiz is over.";
			return;
		}

		std::cout << question;
		std::cin >> bUserAnswer;
	}
}

int main() 
{
	bool answers[3];
	float grade = 0.0f;
	float maxCorrectAnswers = 3;

	std::cout << "Welcome to your quiz!\nAnswer\nF for False\nT for True\nYou only have 3 attempts per cuestion.\n" << std::endl;

	makeQuestion("true?", true);

	makeQuestion("true2?", true);

	
}