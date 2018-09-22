#include "DFT.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
std::vector<ComplexNumber> FourierTransform(std::vector<double> & samples, int sam_p_sec)
{
	int n = samples.size(),
		f, t;
	double r{ 0 }, i{ 0 };
	std::vector<ComplexNumber> a;
	a.resize(n);
	for (f = 0; f < n; ++f) {
		r = i = 0;
		for (t = 0; t < n; ++t) {
			r += samples[t] * cos(2 * M_PI * t * f / n);
			i -= samples[t] * sin(2 * M_PI * t * f / n);
		}
		a[f] = ComplexNumber(r, i);
	}
	return a;
}

std::vector<double> InverseFourierTransform(std::vector<ComplexNumber>& samples, int sam_p_sec)
{
	int n = samples.size(),
		f, t;
	double r{ 0 };
	std::vector<double> s;
	s.resize(n);
	for (t = 0; t < n; ++t) {
		r = 0;
		for (f = 0; f < n; ++f) {
			r += samples[f].get_real_v()*cos(2 * M_PI * f * t / n)
				- samples[f].get_imag_v()*sin(2 * M_PI * f * t / n);
		}
		s[t] = r;
	}
	return s;
}
