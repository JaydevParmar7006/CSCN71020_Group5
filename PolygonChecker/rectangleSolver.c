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


// Function to calculate the area of a rectangle
double calculateArea(double points[4][2]) {
    // Sort points in counterclockwise order
    sortRectanglePoints(points);

    // Calculate lengths of adjacent sides
    double length = calculateDistance(points[0][0], points[0][1], points[1][0], points[1][1]);
    double width = calculateDistance(points[1][0], points[1][1], points[2][0], points[2][1]);

    // Return area
    return round((length * width) * 100.0) / 100.0; // Round to 2 decimal places
}

// Function to calculate the distance between two points
double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Helper function to find the bottom-left point
int findBottomLeftIndex(double points[4][2]) {
    int minIndex = 0;
    for (int i = 1; i < 4; i++) {
        if (points[i][1] < points[minIndex][1] ||
            (points[i][1] == points[minIndex][1] && points[i][0] < points[minIndex][0])) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to calculate angle for sorting
double calculateAngle(double x1, double y1, double x2, double y2) {
    return atan2(y2 - y1, x2 - x1);
}

// Function to sort points in counterclockwise order
void sortRectanglePoints(double points[4][2]) {
    // Find the bottom-left point
    int bottomLeftIndex = findBottomLeftIndex(points);
    double refX = points[bottomLeftIndex][0];
    double refY = points[bottomLeftIndex][1];

    // Swap the bottom-left point with the first point
    double tempX = points[0][0];
    double tempY = points[0][1];
    points[0][0] = refX;
    points[0][1] = refY;
    points[bottomLeftIndex][0] = tempX;
    points[bottomLeftIndex][1] = tempY;

    // Sort the remaining points based on their angles with the reference point
    for (int i = 1; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            double angle1 = calculateAngle(refX, refY, points[i][0], points[i][1]);
            double angle2 = calculateAngle(refX, refY, points[j][0], points[j][1]);
            if (angle1 > angle2) {
                // Swap points[i] and points[j]
                double tempX = points[i][0];
                double tempY = points[i][1];
                points[i][0] = points[j][0];
                points[i][1] = points[j][1];
                points[j][0] = tempX;
                points[j][1] = tempY;
            }
        }
    }
}
