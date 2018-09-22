#pragma once
#include "ComplexNumber.hpp"
#include <vector>
std::vector<ComplexNumber> FourierTransform(std::vector<double> & samples, int sam_p_sec);
std::vector<double> InverseFourierTransform(std::vector<ComplexNumber> & samples, int sam_p_sec);