#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "triangleSolver.h"

#define PI 3.14159265358979323846
#define EPSILON 1e-6 

char* analyzeTriangle(double side1, double side2, double side3) {
	char* result = (char*)malloc(150 * sizeof(char));
	if (result == NULL) {
		printf("Memory allocation is failed.\n");
		return NULL;
	}


	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		printf("Invalid input: Sides must be positive.\n");
		sprintf(result, "Invalid input");
		return result;
	}
	if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
		printf("Not a traingle.\n");
		sprintf(result, "Not a triangle");
		return result;
	}


	if (fabs(side1 - side2) < EPSILON && fabs(side1 - side3) < EPSILON) {
		sprintf(result, "Equilateral triangle.");
	}
	else if (fabs(side1 - side2) < EPSILON ||
		fabs(side1 - side3) < EPSILON ||
		fabs(side2 - side3) < EPSILON) {
		sprintf(result, "Isosceles triangle.");
	}
	else {
		sprintf(result, "Scalene triangle.");
	}


	double angleA = acos((double)(side2 * side2 + side3 * side3 - side1 * side1) / (2.0 * side2 * side3)) * (180.0 / PI);
	double angleB = acos((double)(side1 * side1 + side3 * side3 - side2 * side2) / (2.0 * side1 * side3)) * (180.0 / PI);
	double angleC = 180.0 - angleA - angleB;

	sprintf(result + strlen(result), "Angles: A = %.2f Degrees, B = %.2f Degrees, C = %.2f Degrees", angleA, angleB, angleC);




	

	return result;
}