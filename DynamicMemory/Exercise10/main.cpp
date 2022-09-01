#include <iostream>

//#include "ClassA.h"
//include "ClassB.h"

int main()
{
	std::cout << "Quiz #10" << std::endl;
	std::cout << "So, what I understand of what is happening is that we are calling #include Class A in main and in class A we are using #include ClassB, but the thing is that in class B we are calling #include Class A, so we end in a weird kind of loop were the classes keep calling each other" << std::endl;
	//ClassA MyClassA;
	//ClassB MyClassB;

	std::cout << "\nQuiz #12" << std::endl;
	std::cout << "When we were creating pointers we didn't need the constructor of the class, we only need that it exists. But when we create an instance, we are calling the constructor so we need to define the class" << std::endl;

	return 0;
}