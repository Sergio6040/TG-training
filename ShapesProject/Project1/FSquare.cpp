#include "FSquare.h"

//--------------------------------------------------------------


float FSquare::GetArea() const
{
	return Side * Side;
}

//--------------------------------------------------------------


float FSquare::GetPerimeter() const
{
	return Side * 4;
}