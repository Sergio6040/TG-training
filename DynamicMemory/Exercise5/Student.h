#pragma once
#include <iostream>

class Student
{
	char StudentName[5];
	int StudentAge;

public:

	Student();
	Student( std::string& InName, int InAge);

	std::string GetName() const;
	int GetAge() const;
};

