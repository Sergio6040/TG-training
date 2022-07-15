/*
* Exercise 3 - Integral Limits
* Write a program that will output the upper and lower limits of integral types.
*/
#include <iostream>
#include <climits>

using namespace std;


int main() {
	cout << "Table of integral data type lower and upper limits in c++" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "\tData Type \t\tLower Limit \t\tUpper Limit" << endl;
	cout << "--------------------------------------------------------------------------\n" << endl;

	cout << "\tchar\t\t\t" << CHAR_MIN << "\t\t\t" << CHAR_MAX << endl;
	cout << "\tunsigned char\t\t" << 0 << "\t\t\t" << UCHAR_MAX << endl;
	cout << "\tshort\t\t\t" << SHRT_MIN << "\t\t\t" << SHRT_MAX << endl;
	cout << "\tunsigned short\t\t" << 0 << "\t\t\t" << USHRT_MAX << endl;
	cout << "\tint\t\t\t" << INT_MIN << "\t\t" << INT_MAX << endl;
	cout << "\tunsigned int\t\t" << 0 << "\t\t\t" << UINT_MAX << endl;
	cout << "\tlong long\t\t" << LLONG_MIN << "\t" << LLONG_MAX << endl;
	cout << "\tunsigned long long\t" << 0 << "\t\t\t" << ULLONG_MAX << endl;

}