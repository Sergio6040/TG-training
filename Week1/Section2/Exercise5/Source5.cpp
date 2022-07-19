/*
* Exercise 5 - Coin Flip
Write a simple coin flip program.
Ask the user for their guess on the result, then tell them whether they guessed right or wrong.

Example output
Welcome to Flip-a-Coin!
1 - Heads
2 - Tails

What’s your guess? 2

Your guess: Tails
Actual result: Heads

You lose, LOSER!
*/
#include <iostream>

int main() {

	int guess;

	std::cout << "Welcome to Flip - a - Coin!\n1 - Heads\n2 - Tails\n" << std::endl;

	std::cout << "What's your guess? ";

	std::cin >> guess;

	srand(time(0));//sets a random seed for the rand() function

	int result = 1 + (rand() % 2);//gets a random number between 1 or 2

	std::cout << "\nYour guess: " << guess << std::endl;
	std::cout << "Actual result: " << result << std::endl;

	if (guess == result) {
		std::cout << "You Win!" << std::endl;
	}
	else
	{
		std::cout << "You Lose!" << std::endl;
	}

	
}