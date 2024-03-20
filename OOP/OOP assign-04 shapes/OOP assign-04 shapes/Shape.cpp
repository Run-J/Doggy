#include"Shape.h"

/// \brief Constructor of Shape
/// \details <b>Details</b>
/// 
/// Validate name and colour, then set the name and colour
/// 
/// \param name - const char* - representation of the shape's name
/// \param colour - const char* - representation of the shape's colour
/// \return As this is a constructor for the Shape class, nothing is returned

Shape::Shape(const char* name, const char* colour)
{
	if ( ValidateName(name) )
	{
		strcpy(this->name, name);
	}
	else
	{
		strcpy(this->name, "Unknown");
	}

	if ( ValidateColour(colour) )
	{
		strcpy(this->colour, colour);
	}
	else
	{
		strcpy(this->colour, "undefined");
	}
}


/// \brief Default Constructor of Shape
/// \details <b>Details</b>
/// 
/// Just initialize the name/colour to the Unknown/undefined
/// \param none
/// \return As this is a constructor for the Shape class, nothing is returned

Shape::Shape(void)
{
	strcpy(this->name, "Unknown");
	strcpy(this->colour, "undefined");
}


/// \brief Validate name tool
/// \details <b>Details</b>
/// 
/// Check if the name is Circle, Square, Unknown. If yes, return true, vice versa
/// \param name - const char* - represent the user input name string
/// \return bool value, if true indicate the name user input is valid, vice versa

bool Shape::ValidateName(const char* name)
{
	const char* validNames[NUMOF_VALIDNAMES] = { "Circle", "Square", "Unknown" };
	for (int i = 0; i < NUMOF_VALIDNAMES; i++)
	{
		if ( strcmp(name, validNames[i]) == 0  &&  strlen(name) <= MAX_NAMECHAR - 1 ) // strlen do not count \n
		{
			return true;
			break;
		}
	}

	return false;
}

/// \brief Validate colour tool
/// \details <b>Details</b>
/// 
/// Check if the colour is red, green... If yes, return true, vice versa
/// \param name - const char* - represent the user input colour string
/// \return bool value, if true indicate the colour user input is valid, vice versa

bool Shape::ValidateColour(const char* colour)
{
	const char* validColour[NUMOF_VALIDCOLOURS] = { "red", "green", "blue", "yellow", "purple", "pink", "orange", "undefined" };
	for (int i = 0; i < NUMOF_VALIDCOLOURS; i++)
	{
		if ( strcmp(colour, validColour[i]) == 0  &&  strlen(colour) <= MAX_COLOURCHAR - 1 )
		{
			return true;
			break;
		}
	}

	return false;
}


/// \brief name accessor
/// \param none
/// \return - const char*- return a copy of name

const char* Shape::GetName(void) const
{
	size_t length = strlen(name) + 1;
	char* nameCopy = new char[length]; // remember delete [] after use
	strcpy(nameCopy, name);
	return nameCopy;
}

/// \brief colour accessor
/// \param none
/// \return - const char*- return a copy of colour

const char* Shape::GetColour(void) const
{
	size_t length = strlen(colour) + 1;
	char* colourCopy = new char[length]; // remember delete [] after use
	strcpy(colourCopy, colour);
	return colourCopy;
}

/// \brief name mutator with validate
/// \param name - const char* - the name string of user input
/// \return int, if SUCCESS(0) means set name successfully, vice versa

int Shape::SetName(const char* name)
{
	if ( ValidateName(name) )
	{
		strcpy(this->name, name);
		return SUCCESS;
	}
	else
	{
		return FAILURE; // if failure, caller print error message; leave the attribute value as it was
	}
}

/// \brief colour mutator with validate
/// \param colour - const char* - the colour string of user input
/// \return int, if SUCCESS(0) means set name successfully, vice versa

int Shape::SetColour(const char* colour)
{
	if ( ValidateColour(colour) )
	{
		strcpy(this->colour, colour);
		return SUCCESS;
	}
	else
	{
		return FAILURE; // if failure, caller print error message; leave the attribute value as it was
	}
}