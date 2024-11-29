#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "rectangleSolver.h"


bool isRectangle(double points[4][2]) {
    // Sort points in counterclockwise order
    sortRectanglePoints(points);

    // Calculate distances between adjacent points
    double d1 = calculateDistance(points[0][0], points[0][1], points[1][0], points[1][1]); // Side 1
    double d2 = calculateDistance(points[1][0], points[1][1], points[2][0], points[2][1]); // Side 2
    double d3 = calculateDistance(points[2][0], points[2][1], points[3][0], points[3][1]); // Side 3
    double d4 = calculateDistance(points[3][0], points[3][1], points[0][0], points[0][1]); // Side 4

    // Calculate diagonals
    double diag1 = calculateDistance(points[0][0], points[0][1], points[2][0], points[2][1]); // Diagonal 1
    double diag2 = calculateDistance(points[1][0], points[1][1], points[3][0], points[3][1]); // Diagonal 2

    // Validate: Opposite sides must be equal and diagonals must be equal
    if (fabs(d1 - d3) > 1e-6 || fabs(d2 - d4) > 1e-6 || fabs(diag1 - diag2) > 1e-6) {
        return false; // Not a rectangle
    }

    // Validate: Adjacent sides must be perpendicular (dot product = 0)
    double dot1 = (points[1][0] - points[0][0]) * (points[3][0] - points[0][0]) +
        (points[1][1] - points[0][1]) * (points[3][1] - points[0][1]);
    if (fabs(dot1) > 1e-6) {
        return false; // Adjacent sides are not perpendicular
    }

    return true; // Valid rectangle
}

// Function to calculate the perimeter
double calculatePerimeter(double points[4][2]) {
    // Sort points in counterclockwise order
    sortRectanglePoints(points);

    // Calculate distances between adjacent points
    double d1 = calculateDistance(points[0][0], points[0][1], points[1][0], points[1][1]);
    double d2 = calculateDistance(points[1][0], points[1][1], points[2][0], points[2][1]);
    double d3 = calculateDistance(points[2][0], points[2][1], points[3][0], points[3][1]);
    double d4 = calculateDistance(points[3][0], points[3][1], points[0][0], points[0][1]);

    // Sum the distances
    return round((d1 + d2 + d3 + d4) * 100.0) / 100.0; // Round to 2 decimal places
}


