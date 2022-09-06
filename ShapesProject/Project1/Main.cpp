#include <iostream>
#include "FShape.h"
#include "FCircle.h"
#include "FSquare.h"

#include "ValidateInput.h"

#define Print(Text) std::cout << Text << std::endl;




void AskForShapesBuiltIn()
{
	const int ShapesNumber = GetValidateInput("How many figures do you want to create?");;

	FShape** BuiltInArray = new FShape *[ShapesNumber];

	Print("Specify what figures you want.");

	for (int i = 0; i < ShapesNumber; i++) 
	{
		int ShapeChoice = GetValidateInput(1, 2, i + "\n 1 - Cirle \n 2 - Scuare \n Shape: ");
		system("cls");
		if (ShapeChoice == 1)
		{
			float Radius = GetValidateInput("Enter the radius: ");
			FCircle* Circle = new FCircle(Radius);

			BuiltInArray[i] = Circle;
		}
		else if (ShapeChoice == 2)
		{
			float Size = GetValidateInput("Enter the Size of the edges: ");
			FSquare* Square = new FSquare(Size);

			BuiltInArray[i] = Square;
		}
	}

	Print("----------------Saved Shapes----------------");

	for (int i = 0; i < ShapesNumber; i++)
	{
		float LoopArea = BuiltInArray[i]->GetArea();
		float LoopPerimeter = BuiltInArray[i]->GetPerimeter();

		Print("Shape " << i << " area: " << LoopArea << " perimeter: " << LoopPerimeter);
	}

	std::cin.ignore();
	std::cin.get();

}

void AskForShapesStatic()
{

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

