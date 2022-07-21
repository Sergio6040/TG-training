/*
 * Exercise 2 - More Input Validation
 * Rewrite the true or false quiz you did in the previous section.
 * This time, instead of asking for 1 or 2 as inputs, ask them to answer T or F.
 * If they enter invalid input, give them a couple of tries before you automatically fail them.
 */

#include <iostream>

bool makeQuestion(std::string Question, bool CorrectAnswer)
{
	bool UserAnswer = !CorrectAnswer;
	int Attepts = 0;
	while (UserAnswer != CorrectAnswer && Attepts < 3)
	{
		Attepts++;

		if (Attepts > 1)
			std::cout << "Wrong answer!" << std::endl;
		if (Attepts == 3)
			std::cout << "Last attempt!" << std::endl;

		std::string UserInput;
		std::cout << Question;
		std::cin >> UserInput;

		if (UserInput == "t" || UserInput == "T")
		{
			UserAnswer = true;
		}
		else if (UserInput == "f" || UserInput == "F")
		{
			UserAnswer = false;
		}
		else
		{
			std::cout << "Do not mess with me. Please answer T or F." << std::endl;
		}
	}

	if (Attepts >= 3 && UserAnswer != CorrectAnswer)
	{
		// reprueba
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
	int UserCorrectAnswers = 0;
	float MaxCorrectAnswers = 3;

	// stores the Questions and the correct Answers
	std::string Questions[3] = {
		"Is the ocean a soup? ",
		"Is the forest a salad? ",
		"Is a hot dog a taco though? "};

	bool Answers[3] = {
		true,
		false,
		false};

	std::cout << "Welcome to your quiz!\nAnswer\nF for False\nT for True\nYou only have 3 attempts per cuestion.\n"
			  << std::endl;

	// loop the Questions
	for (int i = 0; i < 3; i++)
	{
		bool result = makeQuestion(Questions[i], Answers[i]);

		if (result)
		{
			UserCorrectAnswers++;
		}
		else
		{
			UserCorrectAnswers = 0;
			break;
		}
	}

	float TotalGrade = (5 * UserCorrectAnswers) / MaxCorrectAnswers;
	std::cout << "\nYou got " << UserCorrectAnswers << "/3 correct Answers!Your final grade is : " << TotalGrade << std::endl;
}