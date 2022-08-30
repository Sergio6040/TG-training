#pragma once
#include <iostream>

class Student
{
	char* StudentName{};
	int StudentAge{};

	char* NameAddress;

public:

	Student();
	~Student();

	std::string GetName() const;
	int GetAge() const;

	void SetName(const char* InName);
	void SetAge(const int InAge);
};

