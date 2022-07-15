/*
* Exercise 2 - Data Type Sizes
* Write a program that will output the size of the different data types in c++.
*/

#include <iostream>

using namespace std;

int main() {
	cout << "Table of basic data type sizes in c++" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "\tData type \t\tSize(bytes)" << endl;
	cout << "------------------------------------------------\n" << endl;

	cout << "\tchar \t\t\t" << sizeof(char) << endl;
	cout << "\tshort \t\t\t" << sizeof(short) << endl;
	cout << "\tint \t\t\t" << sizeof(int) << endl;
	cout << "\tlong \t\t\t" << sizeof(long) << endl;
	cout << "\tlong long \t\t" << sizeof(long long) << endl;
	cout << "\tfloat \t\t\t" << sizeof(float) << endl;
	cout << "\tdouble \t\t\t" << sizeof(double) << endl;
	cout << "\tlong doble \t\t" << sizeof(long double) << endl;
	cout << "\tbool \t\t\t" << sizeof(bool) << endl;
}