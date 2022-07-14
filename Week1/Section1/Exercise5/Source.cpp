/*
*Exercise 5 - Basic Casting
*Write a program that will show the different effects of implicit / explicit casting
*/

#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
	cout << "\n----- Testing explicit casting in c++ -----" << endl;
	cout << "Using 'int a = 4' and 'int b = 7' \n" << endl;

	int a = 4;
	int b = 7;

	cout << "a / b = " << a / b << endl;
	cout << "(float)a / b = " << (float)a / b << endl;
	cout << "a / (float)b = " << a / (float)b << endl;


	cout << "\n----- Testing implicit casting in c++ -----" << endl;
	cout << "Using 'int c = 5' and 'float d = 6.6' \n" << endl;

	int c = 5;
	float d = 6.6f;

	int e = d;
	cout << "int e = d outputs : " << e << " (" << typeid(e).name() << ")" << endl;
	float f = c;
	cout << "float f = c outputs : " << f << " (" << typeid(f).name() << ")" << endl;

}