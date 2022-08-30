#include "Student.h"
#include <string.h>
Student::Student() = default;

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

	memcpy_s(StudentName, Length + 1, InName, Length + 1);

}

void Student::SetAge(const int InAge)
{
	StudentAge = InAge;
}