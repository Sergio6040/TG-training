#include "Student.h"
#include <string.h>
Student::Student() = default;

/*
Student::Student(std::string& InName, int InAge)
{
	if (InName.empty())
	{
		InName = "Joe_";
	}

	for (int i = 0; i < 5; i++)
	{
		StudentName[i] = InName[i];
	}

	StudentAge = InAge;

}*/

std::string Student::GetName() const
{
	return StudentName;
}

int Student::GetAge() const
{
	return StudentAge;
}

void Student::SetName(const char* InName)
{

	size_t Length = strlen(InName);
	StudentName = new char[Length];

	memcpy_s(StudentName, Length, InName, Length);

}

void Student::SetAge(const int InAge)
{
	StudentAge = InAge;
}