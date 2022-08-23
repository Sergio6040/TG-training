/*
* Exercise 3 - Shapes and Areas
* Create two classes: a Circle class and a Square class. For each class, take in the necessary information to calculate its area and perimeter.� Remember to validate input.
*
* Ask the user if they want to create a Circle or a square. For their pick, ask the necessary information to create the shape. Then, tell them the area and the perimeter of their shape.
*
* Your class should have the following methods:
* ExampleShape();
* ExampleShape(/ Params /);
* float GetArea();
* float GetPerimeter();
*/

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>


class FCircle
{
public:
	float Area;
	float Perimeter;

	FCircle()
	{
		Area = 0.0f;
		Perimeter = 0.0f;
	}

	FCircle(float Radius)
	{
		Area = M_PI * pow(Radius, 2);
		Perimeter = M_PI * 2.0f * Radius;
	}

	float GetArea() const
	{
		return Area;
	}

	float GetPerimiter() const
	{
		return Perimeter;
	}

};

class FSquare
{
public:
	float Area;
	float Perimeter;

	FSquare()
	{
		Area = 0.0f;
		Perimeter = 0.0f;
	}

	FSquare(float Side)
	{
		Area = pow(Side, 2);
		Perimeter = 4 * Side;
	}

	float GetArea() const
	{
		return Area;
	}

	float GetPerimiter() const
	{
		return Perimeter;
	}

};

int main()
{
	int Choice;
	
	do
	{
		std::cout << "Welcome to create-a-shape, what type of shape do you want?\n1 - Circle\n2 - Square\nYour Choice : ";
		std::cin >> Choice;

		if (Choice < 1 && Choice > 2)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Wrong input" << std::endl;
			Choice = 0;
		}
	}
	while (Choice == 0);

	float MainArea = 0.0f;
	float MainPerimeter = 0.0f;
	FCircle Circle;
	FSquare Square;

	if (Choice == 1)
	{

		float InputRadius;
		std::cout << "Enter the radius for your Circle: ";
		std::cin >> InputRadius;

		Circle = FCircle(InputRadius);

		MainArea = Circle.GetArea();
		MainPerimeter = Circle.GetPerimiter();
	}
	else if(Choice == 2)
	{
		float InputSide;
		std::cout << "Enter the size for the sides of your square: ";
		std::cin >> InputSide;

		Square = FSquare(InputSide);

		MainArea = Square.GetArea();
		MainPerimeter = Square.GetPerimiter();
	}

	std::cout << "Your shape's Area is: " << MainArea << std::endl;
	std::cout << "Your shape's Perimeter is: " << MainPerimeter << std::endl;


}