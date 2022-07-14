/*
Exercise 7 - Operator Precedence
Write a program that will ask the user for three numbers (a,b,c) and output the following evaluations:
a + 1 * b + 2 - c
(a + 1) * (b + 2) - c

Example output
In c++, arithmetic follows the PEMDAS rule! Check it out:
Enter a value for number a: 5
Enter a value for number b: 10
Enter a value for number c: 6

a + 1 * b + 2 - c	= 11
(a + 1) * (b + 2) - c	= 66
*/
#include <iostream>

using namespace std;

int main() {
	int a, b, c;

	//get the inputs
	cout << "enter a value for a: ";
	cin >> a;
	cout << "enter a value for b: ";
	cin >> b;
	cout << "enter a value for c: ";
	cin >> c;
	cout << "\n";

	//process
	int res1 = a + 1 * b + 2 - c;
	int res2 = (a + 1) * (b + 2) - c;

	cout << " a + 1 * b + 2 - c = " << res1 << endl;
	cout << " (a + 1) * (b + 2) - c = " << res2 << endl;


}