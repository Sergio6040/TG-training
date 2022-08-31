#include <iostream>

#include "ClassA.h"
#include "ClassB.h"

int main()
{
	std::cout << "So, what I understand of what is happening is that we are calling #include Class A in main and in class A we are using #include ClassB, but the thing is that in class B we are calling #include Class A, so we end in a weird kind of loop were the classes keep calling each other" << std::endl;
	ClassA MyClassA;
	ClassB MyClassB;

	return 0;
}