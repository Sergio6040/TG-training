/*
* Exercise 2 - Understanding Stack vs Heap
* Let’s compare the memory addresses of the stack and the heap.
* First, create three int variables called stackInt1, stackInt2, and stackInt3.These variables should
* be allocated in the stack.Initialize them to whatever value you wantand then print their value
* and memory addresses.
* Then, create three more int variablesand call them healpInt1, heapInt2, and heapInt3.These
* variables should be allocated in the heap. Initialize them to whatever value you wantand print
* their value and memory addresses.
* What can you notice from the memory addresses in the stack vs the memory addresses in the
* heap ? Print the answer to that question to the console(Yep, we’re doing quizzes in exercises now).
* Remember to free any memory you allocate in the heap.
*/

#include <iostream>

#define Print(Text) std::cout << Text << std::endl;

int main()
{
	//-----------------------stack--------------------------
	Print("---------------Stack variables--------------");
	int StackInt1{5};
	int StackInt2{10};
	int StackInt3{50};

	Print("value: " << StackInt1 << " at: " << &StackInt1);
	Print("value: " << StackInt2 << " at: " << &StackInt2);
	Print("value: " << StackInt3<< " at: " << &StackInt3);

	//-----------------------heap--------------------------
	Print("--------------Heap variables--------------");
	int* HeapInt1 = new int{ 3 };
	int* HeapInt2 = new int{ 6 };
	int* HeapInt3 = new int{ 18 };

	Print("value: " << *HeapInt1 << " at: " << HeapInt1);
	Print("value: " << *HeapInt2 << " at: " << HeapInt2);
	Print("value: " << *HeapInt3 << " at: " << HeapInt3);

	delete HeapInt1;
	delete HeapInt2;
	delete HeapInt3;


	Print("---------------Quiz---------------");
	Print("What can you notice from the memory addresses in the stack vs the memory addresses in the heap ?");
	Print("R: The stack memory es saved in *Stack* xd each varable is saved in the disc one before another.");
	Print("while the heap is stored in its special space, and is not saved in a row.");


}