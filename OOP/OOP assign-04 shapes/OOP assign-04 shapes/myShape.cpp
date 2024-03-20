// File name: myShape.cpp
// Project: Assign-04 Shapes
// Programmer: Run Ji
// First Version: 2024/02/26
// Description: The user is asked for the desired color and information about the shape. 
//				The program generates the shape based on the user's input and calculates the perimeter and area and 
//				finally displays it.

#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include <string.h>
#include <stdlib.h>

#define USER_CHARACTERS_INPUT 15
#define NUMBER_BUFFER 10

char* getUserCharacterInput(void);
float getUserFloat(void);

int main(void)
{
	// get user's info
	printf("I have created a circle and a square\n");
	printf("Which colour do you like ( red/green/blue/yellow/purple/pink/orange ) >> ");
	char* userColour = getUserCharacterInput();

	printf("Enter circle radius >> ");
	float radius = getUserFloat();

	printf("Enter square sideLength >> ");
	float sideLength = getUserFloat();

	// dynamiclly instantiate
	Circle* myCircle = new Circle(userColour, radius);
	if (myCircle == NULL)
	{
		printf("Memory run out");
		return FAILURE;
	}
	Square* mySquare = new Square(userColour, sideLength);
	if (mySquare == NULL)
	{
		printf("Memory run out");
		return FAILURE;
	}
	delete[] userColour;

	// show shapes info
	myCircle->Show();
	mySquare->Show();

	delete myCircle;
	delete mySquare;
	return 0;
}

char* getUserCharacterInput(void)
{
	char* userShapeChoice = new char[USER_CHARACTERS_INPUT]; // remember delete after use
	if (userShapeChoice == NULL)
	{
		printf("Memory run out");
		exit(FAILURE);
	}
	fgets(userShapeChoice, USER_CHARACTERS_INPUT, stdin);
	userShapeChoice[strcspn(userShapeChoice, "\n")] = 0; // use index to find \n; strcspn return a number not pointer like strchr
	return userShapeChoice;
}

float getUserFloat(void)
{
	char	numberBuffer[NUMBER_BUFFER] = { 0 };
	float 	number = 0.00;

	fgets(numberBuffer, sizeof(numberBuffer), stdin);
	if (sscanf(numberBuffer, "%f", &number) != 1)
	{
		printf("###ERROR: Failed to get float");
	}

	return number;
}
