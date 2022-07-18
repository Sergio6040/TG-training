/*
* Exercise 2 - Even or Odd
Write a program that will ask the user for three numbers, then tell them whether the numbers are even or odd.

Example output
Please enter a value for number a: 5
Please enter a value for number b: 6
Please enter a value for number c: 99

Number a is ODD!
Number b is EVEN!
Number c is ODD!

*/

#include <iostream>

void printEvenOrOdd(int value) {
	if ((value % 2) == 0) {
		std::cout << "Number " << value << " is EVEN!" << std::endl;
	}
	else {
		std::cout << "Number " << value << " is ODD!" << std::endl;
	}
}

int main() {
	int a, b, c;

	std::cout << "Please enter a value for number a: ";
	std::cin >> a;
	std::cout << "Please enter a value for number b: ";
	std::cin >> b;
	std::cout << "Please enter a value for number c: ";
	std::cin >> c;

	printEvenOrOdd(a);
	printEvenOrOdd(b);
	printEvenOrOdd(c);

}

