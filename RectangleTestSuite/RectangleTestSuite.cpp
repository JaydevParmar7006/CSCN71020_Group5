#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "C:\Users\parma\source\repos\CSCN71020_Group5\PolygonChecker\rectangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTestSuite
{
    TEST_CLASS(Rectangle_Validation_Tests)
    {
    public:

        TEST_METHOD(Test_ValidRectangle)
        {
            double points[4][2] = { {0, 0}, {4, 0}, {4, 3}, {0, 3} };
            Assert::IsTrue(isRectangle(points), L"The points should form a valid rectangle.");
        }

        TEST_METHOD(Test_Parallelogram)
        {
            double points[4][2] = { {0, 0}, {3, 1}, {5, 4}, {2, 3} };
            Assert::IsFalse(isRectangle(points), L"The points should not form a rectangle.");
        }

        TEST_METHOD(Test_CollinearPoints)
        {
            double points[4][2] = { {0, 0}, {1, 1}, {2, 2}, {3, 3} };
            Assert::IsFalse(isRectangle(points), L"The points should not form a rectangle.");
        }

        TEST_METHOD(Test_DuplicatePoints)
        {
            double points[4][2] = { {0, 0}, {0, 0}, {4, 3}, {0, 3} };
            Assert::IsFalse(isRectangle(points), L"The points should not form a rectangle.");
        }
    };

    TEST_CLASS(Perimeter_Calculation_Tests)
    {
    public:
        TEST_METHOD(Test_RectanglePerimeter)
        {
            double points[4][2] = { {0, 0}, {4, 0}, {4, 3}, {0, 3} };
            double perimeter = calculatePerimeter(points);
            Assert::AreEqual(14.00, perimeter, 0.01, L"Perimeter should be 14.00 for the rectangle.");
        }

        TEST_METHOD(Test_ParallelogramPerimeter)
        {
            double points[4][2] = { {0, 0}, {3, 1}, {5, 4}, {2, 3} };
            double perimeter = calculatePerimeter(points);
            Assert::AreEqual(13.54, perimeter, 0.01, L"Perimeter should be 13.54 for the shape.");
        }

        TEST_METHOD(Test_CollinearPointsPerimeter)
        {
            double points[4][2] = { {0, 0}, {1, 1}, {2, 2}, {3, 3} };
            double perimeter = calculatePerimeter(points);
            Assert::AreEqual(8.49, perimeter, 0.01, L"Perimeter should be 8.49 for collinear points.");
        }
    };

}