#include "../Fourier/DFT.hpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FourierTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			bool inrange = true;
			std::vector<double> s0{ -.8660254040, .3214394654, .9914448614, .6540312923e-1,
				-.9659258263, -.4422886902, .7933533404, .7518398075,
				-.5000000000, -.9469301295, .1305261922, .9978589232,
				.2588190451, -.8968727415, -.6087614290, .6593458152,
				.8660254040, -.3214394654, -.9914448614, -.6540312923e-1,
				.9659258263, .4422886902, -.7933533404, -.7518398075,
				.5000000000, .9469301295, -.1305261922, -.9978589232,
				-.2588190451, .8968727415, .6087614290, -.6593458152 };
			// TODO: Your test code here
			std::vector<ComplexNumber> a = FourierTransform(s0, 32);
			std::vector<double> s1 = InverseFourierTransform(a, 32);
			for (int i = 0; i < 32; ++i) {
				if (floor(log10(s0[i])) != floor(log10(s1[i]))) inrange = false;
				if(((s0[i] - s1[i]) * pow(10, (floor(log10(s0[i]))))) > 1) inrange = false;
			}
			Assert::IsTrue(inrange);
		}

	};
}