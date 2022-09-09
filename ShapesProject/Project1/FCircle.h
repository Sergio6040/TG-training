#pragma once
#include "FShape.h"

class FCircle : public FShape
{
	float Radius;

public:
	FCircle() = default;

	FCircle(float InRadius) : Radius{ InRadius } {};

	FCircle(FCircle& Object) : Radius(Object.Radius) {};

	float GetArea() const override;

	float GetPerimeter() const override;
}; 
