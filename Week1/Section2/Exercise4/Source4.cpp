/*
Exercise 4 - True or False
Write a quiz program for the user.
The program should ask a series of true or false questions to the user.
For each answer, tell the user if they were correct or incorrect.
At the end of the quiz, tell them their final grade (grade should be 0-5)

Example output
Welcome to your quiz!
0 - False
1 - True

Question 1: Are avocados fruits? 0
WRONG! How could you miss that??

Question 2: Is the sky blue? 1
CORRECT! Looks like you have common sense.

Question 3: Is Teravision the Best.Team.Ever? 1
CORRECT! Looks like you have common sense.

You got 2/3 correct answers! Your final grade is: 3.33
*/
#include <iostream>

int main() {
	bool answers[3];
	float grade = 0.0f;
	float maxGrade = 3;

	std::cout << "Welcome to your quiz!\n0 - False\n1 - True\n" << std::endl;

	std::cout << "1) 2 + 2 = 5 ?" << std::endl;
	std::cin >> answers[0];// false

	if (!answers[0]) {
		//correct answer
		std::cout << "good job!" << std::endl;
		grade++;
	}else {
		//wrong answer
		std::cout << "nope, do the math again" << std::endl;
	}

	std::cout << "2) Does the dogs barks ?" << std::endl;
	std::cin >> answers[1];//true

	if (answers[1]) {
		//correct answer
		std::cout << "Great, continue" << std::endl;
		grade++;
	}else {
		//wrong answer
		std::cout << "please, touch some grass!" << std::endl;
	}

	std::cout << "3) Does she loves you ?" << std::endl;
	std::cin >> answers[2]; //false :c

	if (!answers[2]) {
		//correct answer
		std::cout << "well done bro, she is temporal, coding is 4 ever XD!" << std::endl;
		grade++;
	}else {
		//wrong answer
		std::cout << "sorry bro, that would never happen :C" << std::endl;
	}

	//calculate final grade

	float totalGrade = (5 * grade) / maxGrade;
	std::cout << "\nYou got " << grade << "/3 correct answers!Your final grade is : " << totalGrade << std::endl;


}