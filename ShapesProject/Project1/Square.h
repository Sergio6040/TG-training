#pragma once
#include "Shape.h"

class FSquare : public FShape
{
private:
	float Side;

public:
	FSquare() : Side(0) {};

	FSquare(const float InSide) : Side{InSide} {};

	FSquare(const FSquare &Object) : Side{Object.Side} {};

	float GetArea() const override;

	float GetPerimeter() const override;
};

