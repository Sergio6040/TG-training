/*Exercise 6 - User Input
Write a program that will ask the user to enter their name and their age, then output the days they’ve been alive(ignore leap years).

Example output
Heyo!What’s your name ? Yeison
Nice to meet you, Yeison!What’s your age ? 30


*/

#include <iostream>

using namespace std;

int main() {
	string name;
	int age;

	cout << "Hey! Yo! What is your name ? : ";
	cin >> name;
	cout << "Hey! " << name << " what's ur age? : ";
	cin >> age;

	int days = age * 365;

	cout << "Whats up! " << name << " did you know that you are more or less " << days << " days old ?" << endl;
}