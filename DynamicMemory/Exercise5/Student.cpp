#include "Student.h"
#include <string.h>

Student::Student() = default;

Student::~Student()
{
	memcpy_s(StudentName, strlen(StudentName) + 1, "", strlen(StudentName) + 1);
	StudentAge = 0;
}

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
	if (NameAddress != nullptr)
	{
		//Exercise 9 Solution
		// I stored the old location and clean it
		memcpy_s(NameAddress, strlen(NameAddress) + 1, "", strlen(NameAddress) + 1);

	}

	StudentName = new char[Length];
	NameAddress = StudentName;
	memcpy_s(StudentName, Length + 1, InName, Length + 1);

}

void Student::SetAge(const int InAge)
{
	StudentAge = InAge;
}