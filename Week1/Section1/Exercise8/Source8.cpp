/*
Exercise 8 - Temperature
Write a program that will ask for a temperature in Fahrenheit and convert it to Celsius, then ask for a temperature in Celsius and convert it to Fahrenheit
Hint: 
C = (F - 32.0) * 5.0 / 9.0
F = C * 9.0 / 5.0 + 32.0
Example output
Temperature in F: 100
Temperature in C: 37.7778

Temperature in C: 100
Temperature in F: 212
*/
#include <iostream>

using namespace std;

int main() {
	float f, c;

	cout << "------- Temperature converter -------\n" << endl;
	//get input
	cout << "enter a temperature in Fahrenheit: ";
	cin >> f;
	cout << "enter a temperature in Celsius: ";
	cin >> c;
	//process
	float res1 = (f - 32.0) * 5.0 / 9.0;
	float res2 = c * 9.0 / 5.0 + 32.0;
	//output
	cout << f << " F° to C° => " << res1 << endl;
	cout << c << " C° to F° => " << res2 << endl;

}