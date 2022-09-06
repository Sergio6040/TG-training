#include "FCircle.h"
#include <cmath>

# define M_PI           3.14159265358979323846  /* pi */


float FCircle::GetArea() const
{
	return M_PI * pow(Radius, 2);
}

float FCircle::GetPerimeter() const
{
	return 2 * M_PI * Radius;
}
