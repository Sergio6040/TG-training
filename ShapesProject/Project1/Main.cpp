#include <iostream>
#include "FShape.h"
#include "FCircle.h"
#include "FSquare.h"
#include "TStaticArray.h"

#include "ValidateInput.h"

#define Print(Text) std::cout << Text << std::endl;

FCircle* GetCircle()
{
	float Radius = GetValidateInput("Enter the radius: ");
	FCircle* NewCircle = new FCircle(Radius);

	return NewCircle;
}

FSquare* GetSquare()
{
	float Size = GetValidateInput("Enter the Size of the edges: ");
	FSquare* NewSquare = new FSquare(Size);
	return NewSquare;
}

template<typename T>
void PrintArray(T& InArray, int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		float LoopArea = InArray[i]->GetArea();
		float LoopPerimeter = InArray[i]->GetPerimeter();

		Print("Shape " << i << " area: " << LoopArea << " perimeter: " << LoopPerimeter);
	}

	std::cin.ignore();
	std::cin.get();
}


void AskForShapesBuiltIn()
{
	const int ShapesNumber = GetValidateInput("How many figures do you want to create?");;

	FShape** BuiltInArray = new FShape *[ShapesNumber];

	Print("Specify what figures you want.");

	for (int i = 0; i < ShapesNumber; i++) 
	{
		int ShapeChoice = GetValidateInput(1, 2, i + "\n 1 - Cirle \n 2 - Square \n Shape: ");
		system("cls");
		if (ShapeChoice == 1)
		{
			FCircle* Circle = GetCircle();
			BuiltInArray[i] = Circle;
		}
		else if (ShapeChoice == 2)
		{
			
			FSquare* Square = GetSquare();
			BuiltInArray[i] = Square;
		}
	}

	Print("----------------Saved Shapes----------------");

	PrintArray(BuiltInArray, ShapesNumber);

}

void AskForShapesStatic()
{
	TStaticArray<FShape*, 5> StaticArray;

	Print("Specify what figures you want.");
	for (int i = 0; i < 5; i++)
	{
		int ShapeChoice = GetValidateInput(1, 2, i + "\n 1 - Cirle \n 2 - Square \n Shape: ");
		system("cls");
		if (ShapeChoice == 1)
		{
			FCircle* Circle = GetCircle();
			StaticArray[i] = Circle;
		}
		else if (ShapeChoice == 2)
		{

			FSquare* Square = GetSquare();
			StaticArray[i] = Square;
		}
	}

	PrintArray(StaticArray, 5);
}

void AskForShapesDynamic()
{

}

int main()
{
	while(true)
	{
		system("cls");
		Print("Please select an option:");
		Print("\n\t1 - Built-in Array \n\t2 - Static Array \n\t3 - Dynamic Array \n\t4 - Exit");
		int UserChioce;
		std::cin >> UserChioce;

		switch (UserChioce)
		{
		case 1:
			AskForShapesBuiltIn();
			break;

		case 2:
			AskForShapesStatic();
			break;

		case 3:
			AskForShapesDynamic();
			break;

		case 4:
			return 0;

		default:
			std::cin.clear();
			std::cin.ignore(100, '\n');
			break;
		}
	}
}

