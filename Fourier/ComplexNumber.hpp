#pragma once
class ComplexNumber{
	double real;
	double imag;
public:
	double get_real_v();
	double get_imag_v();
	//The above isn't very secure but what's the chance of some hacker finding this useful
	double originDistance();
	double getPhase();
	ComplexNumber(float r = 0, float i = 0);
};