#include<string.h>
#include<stdio.h>

#ifndef _SHAPEH_
#define _SHAPEH_

#pragma warning (disable:4996)

#define MAX_NAMECHAR 51 // 1 for \0
#define MAX_COLOURCHAR 11
#define NUMOF_VALIDNAMES 3
#define NUMOF_VALIDCOLOURS 8
#define FAILURE 1
#define SUCCESS 0

/// \class Shape
/// \brief This class is the parent class. Contains two properties, name and color.

class Shape
{
private:
	char name[MAX_NAMECHAR]; ///<This string use to store shape's name, like circle, square...
	char colour[MAX_COLOURCHAR]; ///<This string use to store shape's color, like blue, pink...

	static bool ValidateName(const char* name);
	static bool ValidateColour(const char* colour);

public:
	//constructor
	Shape(const char* name, const char* colour);
	Shape(void);
	// accessor
	const char* GetName(void) const;
	const char* GetColour(void) const;
	// mutator
	int SetName(const char* name);
	int SetColour(const char* colour);

	virtual float Perimeter(void) const = 0;
	virtual float Area(void) const = 0;
	virtual float OverallDimension(void) const = 0;
};

#endif _SHAPEH_