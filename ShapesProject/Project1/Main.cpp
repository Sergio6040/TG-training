#include <iostream>
#include "FShape.h"
#include "FCircle.h"
#include "FSquare.h"
#include "TStaticArray.h"
#include "TDynamicArray.h"

#include "ValidateInput.h"

#define Print(Text) std::cout << Text << std::endl;

//------------------------------------------------------------------------------------------

FCircle* GetCircle()
{
	float Radius = GetValidateInput("Enter the radius: ");
	FCircle* NewCircle = new FCircle(Radius);

	return NewCircle;
}

//------------------------------------------------------------------------------------------

FSquare* GetSquare()
{
	float Size = GetValidateInput("Enter the Size of the edges: ");
	FSquare* NewSquare = new FSquare(Size);
	return NewSquare;
}

//------------------------------------------------------------------------------------------

template<typename T>
void PrintArray(const T& InArray, int InSize)
{
	system("cls");
	Print("--------------------------Array Content--------------------------");
	for (int i = 0; i < InSize; i++)
	{
		float LoopArea = InArray[i]->GetArea();
		float LoopPerimeter = InArray[i]->GetPerimeter();

		Print("Shape " << i << " area: " << LoopArea << " perimeter: " << LoopPerimeter);
	}

	std::cin.ignore();
	std::cin.get();
}

//------------------------------------------------------------------------------------------

//template<typename T>
//void ClearArray(const T& InArray, int ArraySize)
//{
//	for (int i = 0; i < ArraySize; i++)
//	{
//		delete InArray[i];
//	}
//}

//------------------------------------------------------------------------------------------

FShape* AskForShapes()
{
	system("cls");
	int ShapeChoice = GetValidateInput(1, 2, "\n 1 - Cirle \n 2 - Square \n Shape: ");
	if (ShapeChoice == 1)
	{
		return GetCircle();
	}
	else if (ShapeChoice == 2)
	{
		return GetSquare();
	}
}

//------------------------------------------------------------------------------------------

void AskForShapesBuiltIn()
{
	const int ShapesNumber = GetValidateInput("How many figures do you want to create?");;

	FShape** BuiltInArray = new FShape *[ShapesNumber];

	Print("Specify what figures you want.");

	for (int i = 0; i < ShapesNumber; i++) 
	{
		BuiltInArray[i] = AskForShapes();
	}

	Print("----------------Saved Shapes----------------");

	PrintArray(BuiltInArray, ShapesNumber);

}

//------------------------------------------------------------------------------------------

void AskForShapesStatic()
{
	TStaticArray<FShape*, 5> StaticArray;

	Print("Specify what figures you want.");
	for (int i = 0; i < 5; i++)
	{
		StaticArray[i] = AskForShapes();
	}

	PrintArray(StaticArray, 5);
}

//------------------------------------------------------------------------------------------

void AskForShapesDynamic()
{
	system("cls");
	TDynamicArray<FShape*> DynamicArray;
	while (true)
	{
		int UserChoice = GetValidateInput(1, 2, "\t1 - Show Figures \n\t2 - Add Shape \n\t3 - Return to main menu");

		if (UserChoice == 1)
		{
			PrintArray(DynamicArray, DynamicArray.GetSize());
		}
		else if(UserChoice == 2)
		{
			/*int ShapeChoice = GetValidateInput(1, 2, DynamicArray.GetSize() + "\n 1 - Cirle \n 2 - Square \n Shape: ");
			system("cls");
			if (ShapeChoice == 1)
			{
				FCircle* Circle = GetCircle();
				DynamicArray.PushBack(Circle);
			}
			else if (ShapeChoice == 2)
			{

				FSquare* Square = GetSquare();
				DynamicArray.PushBack(Square);

			}*/
			DynamicArray.PushBack(AskForShapes());

		}
		else
		{
			break;
		}
	}

}

//------------------------------------------------------------------------------------------

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

