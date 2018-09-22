#define _USE_MATH_DEFINES
#include "ComplexNumber.hpp"
#include <math.h>
double ComplexNumber::get_real_v()
{
	return real;
}
double ComplexNumber::get_imag_v()
{
	return imag;
}
double ComplexNumber::originDistance()
{
	return sqrt(real*real + imag*imag);
}

double ComplexNumber::getPhase()
{
	if (acos(real / this->originDistance()) > 0)
		return asin(imag / this->originDistance());
	return M_PI - asin(imag / this->originDistance());
}

ComplexNumber::ComplexNumber(float r, float i)
{
	real = r;
	imag = i;
}
