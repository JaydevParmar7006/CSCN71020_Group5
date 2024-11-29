#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
	char* analyzeTriangle(double side1, double side2, double side3);
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleTestSuite
{
	TEST_CLASS(EquilateralTriangle)
	{
	public:

		TEST_METHOD(TestEquilateral_AllSidesAreEqual)
		{
			double side1 = 5.0, side2 = 5.0, side3 = 5.0;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::IsTrue(strstr(result, "Equilateral triangle.") != NULL, L"Triangle type is incorrect.");
			Assert::IsTrue(strstr(result, "Angles: A = 60.00 Degrees, B = 60.00 Degrees, C = 60.00 Degrees") != NULL, L"Angles do not match expected values.");
			free(result);
		}
	};
	TEST_CLASS(IsoscelesTriangle)
	{
	public:

		TEST_METHOD(TestIsosceles_TwoSidesAreEqual)
		{
			double side1 = 5.0, side2 = 5.0, side3 = 8.0;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::IsTrue(strstr(result, "Isosceles triangle.") != NULL, L"Triangle type is incorrect.");
			Assert::IsTrue(strstr(result, "Angles: A = 36.87 Degrees, B = 36.87 Degrees, C = 106.26 Degrees") != NULL, L"Angles do not match expected values.");
			free(result);
		}
	};

}

