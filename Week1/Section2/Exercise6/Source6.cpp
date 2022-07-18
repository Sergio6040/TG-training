/*
Exercise 6 - Multiple Choice
Write a program where the user can make a choice out of a list of options. Make sure to use an enum and handle when the input is out of bounds.

Example output
Welcome to Teravision Games! What would you like to know about?
1 - Programming
2 - Game Art
3 - Tech Art
4 - Music Production

Your choice: 3
Cool! You should probably go talk to Dan about that!
*/
#include <iostream>

enum pokemons{
	charmander = 1, bulbasaur, squirtle, pikachu
};

int main() {
	int option;
	std::cout << "Choose your Pokemon?" << std::endl;

	std::cout << "1 - Charmander\n2 - Bulbasaur\n3 - Squirtle\n4 - Pikachu\n>>";
	std::cin >> option;

	switch (option){
		case charmander:
			std::cout << "Cool! You chose a fire type Pokemon!" << std::endl;
			break;
		case bulbasaur:
			std::cout << "Great! You chose a plant type Pokemon!" << std::endl;
			break;
		case squirtle:
			std::cout << "Freshh!! You chose the best pokemon \nVamo a calmarno!" << std::endl;
			break;
		case pikachu:
			std::cout << "pika! pika! Pikachu!" << std::endl;
			break;

		default:
			std::cout << "Incorrect option" << std::endl;
			break;
	}
}