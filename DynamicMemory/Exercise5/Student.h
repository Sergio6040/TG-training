#pragma once
#include <iostream>

class Student
{
	char* StudentName;
	int StudentAge;

public:

	Student();
	//Student( const char* InName, int InAge);

	std::string GetName() const;
	int GetAge() const;

	void SetName(const char* InName);
	void SetAge(const int InAge);
};

