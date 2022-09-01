/*
* Exercise 5 - Dynamic Allocation for Array Sizes
* Create a Student class that contains a char array of size 5 for a name and an int for an age.
*
* Ask the user to enter how many students they want in a class.
* Then, initialize an array of students in the heap of exactly the size they asked for.
* You can now probably tell how dynamic allocation is useful.
*
* Ask the user for a name and an age for each student and then print them all to the screen. Note
* that you won’t be able to use names longer than 4 characters.
* Remember to free any allocated memory.
*/
#include <iostream>
#include "Student.h"

Student* StudentsList;

void ShowStudents(const int ArraySize)
{
	std::cout << "\n\t Students List" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << "Name \t\tAge" << std::endl;

	for (int i = 0; i < ArraySize; i++)
	{
		std::cout << StudentsList[i].GetName() << "\t" << StudentsList[i].GetAge() << std::endl;
	}

}

int main()
{
	Student* TestStudent = new Student();
	TestStudent->SetName("Joe");
	TestStudent->SetAge(8);

	delete TestStudent;

	std::cout << "How many students do you want in your class? " << std::endl;
	int ArraySize;
	std::cin >> ArraySize;

	if (ArraySize > 0 && std::cin.good())
	{
		StudentsList = new Student[ArraySize];

		for (int i = 0; i < ArraySize; i++)
		{
			system("cls");

			std::cout << "Enter student #" << i << " name" << std::endl;
			char NewName[32];
			std::cin >> NewName;

			std::cout << "Enter student #" << i << " Age" << std::endl;
			int NewAge;
			std::cin >> NewAge;

			if (NewAge > 0 && std::cin.good())
			{
				std::cout << "saving..." << std::endl;
				Student NewStudent;
				NewStudent.SetName(NewName);
				//NewStudent.SetName(NewName);
				NewStudent.SetAge(NewAge);
				StudentsList[i] = NewStudent;
			}
			else
			{
				system("cls");
				std::cout << "Wrong age! add the student again." << std::endl;
				i--;
				std::cin.ignore(100, '\n');
				std::cin.get();
			}
			std::cin.clear();
			std::cin.ignore();
		}
		ShowStudents(ArraySize);

	}
	//Quiz #6
	std::cout << "\nmemcpy_s is the most efficient, easy and readable way to copy an array, instead of using an for loop" << std::endl;

	//Quizz #7
	std::cout << "\nWhy deleting the student object does not delete the name’s char array?" << std::endl;
	std::cout << "R: What happened when using the delete keyword, is that the memory space where the object was saved is now free, but its variable values are still there as garbage, they are meant to be replaced by the new entering values :)" << std::endl;

	delete[] StudentsList;
}