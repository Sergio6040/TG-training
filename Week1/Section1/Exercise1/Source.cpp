/*
* Exercise 1 - Hello World
* Write a program that will output “Hello World!” in the first line, then your name and something about yourself in the second line.
*/

#include <iostream>

void Log(const char* message) {
	std::cout << message << std::endl;
}

int main() {
	Log("Hello World! Again!");
	Log("I'm Sergio Sanchez and I love VideoGames (/_ _ )/");
}