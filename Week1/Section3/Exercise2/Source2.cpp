/*
 * Exercise 2 - More Input Validation
 * Rewrite the true or false quiz you did in the previous section.
 * This time, instead of asking for 1 or 2 as inputs, ask them to answer T or F.
 * If they enter invalid input, give them a couple of tries before you automatically fail them.
 */

#include <iostream>

bool MakeQuestion(std::string Question, bool bCorrectAnswer)
{
	bool bQuestionSucceded = false;
	int Attempts = 0;
	
	do
	{
		Attempts++;

		if (Attempts > 1)
		{
			std::cout << "Wrong answer!" << std::endl;
		}
		if (Attempts == 3)
		{
			std::cout << "Last attempt!" << std::endl;
		}

		std::string UserInput;
		std::cout << Question;
		std::cin >> UserInput;

		bool bUserAnswer;
		bool bIsValidInput;

		if (UserInput == "t" || UserInput == "T")
		{
			bUserAnswer = true;
			bIsValidInput = true;
		}
		else if (UserInput == "f" || UserInput == "F")
		{
			bUserAnswer = false;
			bIsValidInput = true;
		}
		else
		{
			std::cout << "Do not mess with me. Please answer T or F." << std::endl;
			bIsValidInput = false;
		}

		bQuestionSucceded = bIsValidInput && (bUserAnswer == bCorrectAnswer);
	} 
	while (!bQuestionSucceded && Attempts < 3);

	if (Attempts >= 3 && !bQuestionSucceded)
	{
		// fail the test
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
	// stores the Questions and the correct Answers
	std::string Questions[3] = {
		"Is the ocean a soup? ",
		"Is the forest a salad? ",
		"Is a hot dog a taco though? "
	};

	bool Answers[3] = {
		true,
		false,
		false
	};

	std::cout << "Welcome to your quiz!\nAnswer\nF for False\nT for True\nYou only have 3 attempts per cuestion.\n" << std::endl;

	bool bQuizApproved;
	// loop the Questions
	for (int i = 0; i < 3; i++)
	{
		bool bResult = MakeQuestion(Questions[i], Answers[i]);

		if (!bResult)
		{
			bQuizApproved = false;
			break;
		}
		else
		{
			bQuizApproved = true;
		}
	}

	if (bQuizApproved)
	{
		std::cout << "Nice you pass the quiz!" << std::endl;
	}
	else
	{
		std::cout << "You fail the test" << std::endl;
	}

}