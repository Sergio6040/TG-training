/*
* Exercise 1 - Understanding classes
* Create a class called FirstClass with a public constructor and destructor. Have the constructor output �I�m in the constructor!� and have the destructor output �I�m in the destructor!�. 
* Then, instantiate 5 classes and run your program, are the constructor and destructor calls where you expected them to be?
* Now create a loop of at least five iterations. For each iteration, instantiate your class once. Run your program, are the constructor and destructor calls where you expected them to be?
*/

#include <iostream>

class FFirstClass
{
public:
	int Value;

	FFirstClass(int NewValue)
	{
		//I create this variable to identify the diferent instances. This was interesting I try using "this.Value" but VS correct me and use "this->Value" :)
		Value = NewValue;
		std::cout << "I'm the Constructor " << Value << std::endl;
	}

	~FFirstClass()
	{
		std::cout << "I'm the Destructor " << Value << std::endl;
	}

};

int main()
{
	FFirstClass Instance1(1);
	FFirstClass Instance2(2);
	FFirstClass Instance3(3);
	FFirstClass Instance4(4);
	FFirstClass Instance5(5);

	for (int i = 0; i < 5; i++)
	{
		FFirstClass LoopInstance(i);
	}
}