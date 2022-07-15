/*
* Exercise 4 - Underflow and Overflow
* Write a program that will illustrate overflow and underflow.
*/

#include <iostream>
#include <climits>

using namespace std;

int main() {

	cout << "Sometimes overflow and underflow can happen if we're not careful with our data sizes and values!\n" << endl;

	cout << "Overflow can happen when we evaluate " << INT_MAX << " + 1.\n The resulting value will be : " << INT_MAX + 1 << endl;

	cout << "\nUnderflow can happen when we evaluate " << INT_MIN << " - 1.\n The resulting value will be : " << INT_MIN - 1 << endl;

}