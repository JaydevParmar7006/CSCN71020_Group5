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


	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}