#include "Square.h"

/// \brief Constructor of Square
/// \details <b>Details</b>
/// 
/// Validate sideLength, then set sideLength from parameter input(valid) or 0.00.
/// 
/// \param colour - char* - representation of the shape's colour
/// \param sideLength - float - representation of the square's sideLength
/// \return As this is a constructor for the Square class, nothing is returned
/// \see ~Square()

Square::Square(char* colour, float sideLength) : Shape("Square", colour)
{
	if ( ValidateSideLength(sideLength) )
	{
		this->sideLength = sideLength;
	}
	else
	{
		this->sideLength = 0.00;
	}

}


/// \brief Default Constructor of Square
/// \details <b>Details</b>
/// 
/// Set sideLength to initial number(0.00)
/// 
/// \param none
/// \return As this is a constructor for the Square class, nothing is returned
/// \see ~Square()

Square::Square(void) : sideLength(0.00)
{
}


/// \brief Destructor of Square
/// \details <b>Details</b>
/// 
/// Shows a message that Square already broken after object destory
/// 
/// \param none
/// \return As this is a constructor for the Square class, nothing is returned
/// \see Square()

Square::~Square(void)
{
	printf("The square is squished ...\n");
}


/// \brief Validate SideLength tool
/// \details <b>Details</b>
/// 
/// Check if the SideLength is greater than 0.00. If yes, return true, vice versa
/// \param radius - float - represent the user input SideLength
/// \return bool value, if true indicate the SideLength user input is valid, vice versa

bool Square::ValidateSideLength(float sideLength)
{
	if (sideLength >= 0.00)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/// \brief SideLength accessor
/// \param none
/// \return - float - return the SideLength

float Square::GetSideLength(void) const
{
	return sideLength;
}


/// \brief SideLength mutator
/// \param radius - float - user input SideLength
/// \return - int - if SUCCESS(0) means set SideLength(valid) successfully, vice versa

int Square::SetSideLength(float sideLength)
{
	if ( ValidateSideLength(sideLength) )
	{
		this->sideLength = sideLength;
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}


/// \brief just shows all of info about shapes
/// \param none
/// \return none

void Square::Show(void)
{
	float perimeter = Perimeter();
	float area = Area();
	const char* name = GetName();
	const char* colour = GetColour();

	printf
	(
		"Shape Information\n"
		"Name            : %s\n"
		"Colour          : %s\n"
		"Side-Length     : %.2f cm\n"
		"Perimeter       : %.2f cm\n"
		"Area            : %.2f square cm\n",
		name, colour, sideLength, perimeter, area
	);

	delete[] name;
	delete[] colour;
}


/// \brief calculate perimeter and return
/// \param none
/// \return - float - indicate perimeter

float Square::Perimeter(void) const
{
	return 4 * sideLength;
}


/// \brief calculate area and return
/// \param none
/// \return - float - indicate area

float Square::Area(void) const
{
	return sideLength * sideLength;
}


/// \brief calculate dimension and return
/// \param none
/// \return - float - indicate dimension

float Square::OverallDimension(void) const
{
	return sideLength;
}
