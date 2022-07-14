/*
Exercise 10 - Swapping
Write a program that will swap the value of two variables

Example output
Please enter two numbers: 6 5

Your first number: 6
Your second number: 5

Your first number swapped: 5
Your second number swapped: 6
*/

#include <iostream>

using namespace std;

int main() {

	int num1, num2, aux;

	cout << "Please enter two numbers:" << endl;
	cout << ">>";
	cin >> num1;
	cout << ">>";
	cin >> num2;

	//uses an auxiliar variable to store the value of num1
	aux = num1;
	num1 = num2; //overrides num1
	num2 = aux;

	cout << "Your numbers has been swaped!" << endl;
	cout << "num1 : " << num1 << endl;
	cout << "num2 : " << num2 << endl;
}