/*
Exercise 9 - Shopping
Write a program that will simulate a shop where you can buy different items. Let the user choose how many items of each type they want, 
and then output the final price. Make sure to combine integer and floating-point types

Example output
Welcome to my no-creativity shop!
------------------------------------------------
Generic Item 1: 10 gold each
Generic Item 2: 6 gold each
Generic Item 3: 15 gold per ounce

How many items 1 do you want? 3
How many items 2 do you want? 6
How much item 3 do you want? 4.3

3 items 1: 30 gold
6 items 2: 36 gold
4.3 ounces of items 3: 64.5 gold

Your total cost is 130.5 gold!!
*/

#include <iostream>

using namespace std;

int main() {

	int item1, item2, item3;
	float item4;
	//menu
	cout << "***************************************************************************" << endl;
	cout << "*                                                                         *" << endl;
	cout << "*\t***Welcom to Porkrind's Emporium! What do you want pal?***        *" << endl;
	cout << "*\t   |-------------------------------------------------|            *" << endl;
	cout << "*\t   | item1 -> Health Biscuit (Extra life): 4 coin$   |            *" << endl;
	cout << "*\t   | item2 -> Cherry Bomb (Granade): 6 coin$         |            *" << endl;
	cout << "*\t   | item3 -> Bubble Gum (Ammo): 2 coin$             |            *" << endl;
	cout << "*\t   | item4 -> Quipitos (Gun powder): 0.5 coin$ x gram|            *" << endl;
	cout << "*\t   |-------------------------------------------------|            *" << endl;
	cout << "*                                                                         *" << endl;
	cout << "***************************************************************************" << endl;
	//input
	cout << ">> How many Health Biscuits do you want?: ";
	cin >> item1;
	cout << ">> How many Cherry Bombs do you want?: ";
	cin >> item2;
	cout << ">> How many Bubble Gum do you want?: ";
	cin >> item3;
	cout << ">> How much Quipitos do you want?: ";
	cin >> item4;
	//output
	float total = (item1 * 4) + (item2 * 6) + (item3 * 2) + (item4 * 0.5);
	cout << "\n\t\tYour total will be: " << total << " coin$" << endl;


}