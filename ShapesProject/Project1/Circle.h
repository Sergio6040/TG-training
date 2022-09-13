#pragma once
#include "Shape.h"

class FCircle : public FShape
{
private:
	float Radius;

public:
	FCircle() : Radius(0) {};

	FCircle(const float InRadius) : Radius(InRadius) {};

	FCircle(const FCircle& Object) : Radius(Object.Radius) {};

	float GetArea() const override;

	float GetPerimeter() const override;
}; 
