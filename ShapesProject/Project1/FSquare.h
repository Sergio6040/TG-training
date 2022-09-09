#pragma once
#include "FShape.h"

class FSquare : public FShape
{
	float Side;

public:
	FSquare() = default;

	FSquare(float InSide) : Side{InSide} {};

	FSquare(FSquare &Object) : Side{Object.Side} {};

	float GetArea() const override;

	float GetPerimeter() const override;
};

