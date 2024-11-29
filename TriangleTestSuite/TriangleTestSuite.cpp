#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "C:\Users\parma\source\repos\CSCN71020_Group5\PolygonChecker\triangleSolver.h"
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

	TEST_CLASS(ScaleneTriangle)
	{
	public:

		TEST_METHOD(TestScalene_AllSidesDifferent)
		{
			double side1 = 3.0, side2 = 4.0, side3 = 5.0;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::IsTrue(strstr(result, "Scalene triangle.") != NULL, L"Triangle type is incorrect.");
			Assert::IsTrue(strstr(result, "Angles: A = 36.87 Degrees, B = 53.13 Degrees, C = 90.00 Degrees") != NULL, L"Angles do not match expected values.");
			free(result);
		}
	};

	TEST_CLASS(ToCheck_IfForms_A_TriangleOrNot)
	{
	public:

		TEST_METHOD(TestNotATriangle_OneSideTooLong)
		{

			double side1 = 1.0, side2 = 2.0, side3 = 10.0;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", result);
			free(result);
		}

		TEST_METHOD(TestNotATriangle_InequalityTheorem_NotFollowed)
		{

			double side1 = 1.0, side2 = 2.0, side3 = 1.0;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", result);
			free(result);
		}
	};

	TEST_CLASS(ToCheck_InvalidInput)
	{
	public:

		TEST_METHOD(TestInvalidInput_NegativeSides)
		{

			double side1 = -5.0, side2 = 5.0, side3 = 5.0;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Invalid input", result);
			free(result);
		}

		TEST_METHOD(TestInvalidInput_ZeroSides)
		{

			double side1 = 0.0, side2 = 5.0, side3 = 5.0;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Invalid input", result);
			free(result);
		}
	};
}

