/*
* Exercise 2 - More Input Validation
* Rewrite the true or false quiz you did in the previous section. 
* This time, instead of asking for 1 or 2 as inputs, ask them to answer T or F. 
* If they enter invalid input, give them a couple of tries before you automatically fail them.
*/

#include <iostream>

bool makeQuestion(std::string question, bool correctAnswer) 
{
	bool userAnswer = !correctAnswer;
	int attepts = 0;
	while (userAnswer != correctAnswer && attepts < 3)
	{
		attepts++;

		if (attepts > 1) std::cout << "Wrong answer!" << std::endl;
		if (attepts == 3) std::cout << "Last attempt!" << std::endl;

		std::string userInput;
		std::cout << question;
		std::cin >> userInput;

		if (userInput == "t" || userInput == "T")
		{
			userAnswer = true;
		}
		else if (userInput == "f" || userInput == "F")
		{
			userAnswer = false;
		}
		else {
			std::cout << "Do not mess with me. Please answer T or F." << std::endl;

		}
	}

	if (attepts >= 3 && userAnswer != correctAnswer) {
		//reprueba
		std::cout << "Number of attempts exceeded!" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Correct answer!" << std::endl;
		return true;
	}
}

int main() 
{
	int userCorrectAnswers = 0;
	float maxCorrectAnswers = 3;

	//stores the questions and the correct answers
	std::string questions[3] = {
		"Is the ocean a soup? ",
		"Is the forest a salad? ",
		"Is a hot dog a taco though? "
	};

	bool answers[3] = {
		true,
		false,
		false
	};

	std::cout << "Welcome to your quiz!\nAnswer\nF for False\nT for True\nYou only have 3 attempts per cuestion.\n" << std::endl;


	//loop the questions
	for (int i = 0; i < 3; i++)
	{
		bool result = makeQuestion(questions[i], answers[i]);

		if (result)
		{
			userCorrectAnswers++;
		}
		else
		{
			userCorrectAnswers = 0;
			break;
		}
		
	}

	float totalGrade  = (5 * userCorrectAnswers) / maxCorrectAnswers;
	std::cout << "\nYou got " << userCorrectAnswers << "/3 correct answers!Your final grade is : " << totalGrade << std::endl;
}