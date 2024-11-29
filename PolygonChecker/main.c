#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1: {
			printf_s("Triangle selected.\n");
			double triangleSides[3] = { 0.0, 0.0, 0.0 };
			double* triangleSidesPtr = getTriangleSides(triangleSides);
			
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			if (result == NULL) {
				printf("Error: Traingle is not analyzed, due to memory allocation failure.\n");
			}
			else {
				printf("Triangle analysis result: %s\n", result);
				free(result);
			}
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

double* getTriangleSides(double* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		while (true) {
			printf("Side %d: ", i + 1);
			int result = scanf_s("%lf", &triangleSides[i]);

			if (result == 1 && triangleSides[i] > 0.0) {
				break;
			}
			else {
				printf("Invalid input. Please enter a valid input.\n");

				while (getchar() != '\n');
			}

		}

	}
	return triangleSides;
} 


void getRectanglePoints(double points[4][2]) {
	printf_s("Enter the coordinates of four points (x y) separated by spaces:\n");
	for (int i = 0; i < 4; i++) {
		while (true) {
			printf("Point %d: ", i + 1);
			if (scanf_s("%lf %lf", &points[i][0], &points[i][1]) == 2) {
				break;
			}
			else {
				printf("Invalid input. Please enter two numeric values for Point %d.\n", i + 1);
				while (getchar() != '\n');
			}
		}
	}
}
