#include"Circle.h"

/// \brief Constructor of Circle
/// \details <b>Details</b>
/// 
/// Validate radius, then set radius from parameter input or 0.00.
/// 
/// \param colour - char* - representation of the shape's colour
/// \param radius - float - representation of the circle's radius
/// \return As this is a constructor for the Circle class, nothing is returned
/// \see ~Circle()

Circle::Circle(char* colour, float radius) : Shape("Circle", colour)
{
	if ( ValidateRadius(radius) )
	{
		this->radius = radius;
	}
	else
	{
		this->radius = 0.00;
	}
}


/// \brief Default Constructor of Circle
/// \details <b>Details</b>
/// 
/// Set radius to initial number(0.00)
/// 
/// \param none
/// \return As this is a constructor for the Circle class, nothing is returned
/// \see ~Circle()

Circle::Circle(void) : radius(0.00)
{
}


/// \brief Destructor of Circle
/// \details <b>Details</b>
/// 
/// Shows a message that circle already broken after object destory
/// 
/// \param none
/// \return As this is a constructor for the Circle class, nothing is returned
/// \see Circle()

Circle::~Circle(void)
{
	printf("The circle is broken ...\n");
}


/// \brief Validate radius tool
/// \details <b>Details</b>
/// 
/// Check if the radius is greater than 0.00. If yes, return true, vice versa
/// \param radius - float - represent the user input radius
/// \return bool value, if true indicate the radius user input is valid, vice versa

bool Circle::ValidateRadius(float radius)
{
	if (radius >= 0.00)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/// \brief radius accessor
/// \param none
/// \return - float - return the radius

float Circle::GetRadius(void)
{
	return radius;
}


/// \brief radius mutator
/// \param radius - float - user input radius
/// \return - int - if SUCCESS(0) means set radius(valid) successfully, vice versa

int Circle::SetRadius(float radius)
{
	if ( ValidateRadius(radius) )
	{
		this->radius = radius;
		return SUCCESS;
	}
	else
	{
		return FAILURE; // if failure, caller print error message radius didt change; leave the attribute value as it was
	}

}


/// \brief just shows all of info about shapes
/// \param none
/// \return none

void Circle::Show(void)
{
	float circumference = Perimeter();
	float area = Area();
	const char* name = GetName();
	const char* colour = GetColour();

	printf
	(
		"Shape Information\n"
		"Name            : %s\n"
		"Colour          : %s\n"
		"Radius          : %.2f cm\n"
		"Circumference   : %.2f cm\n"
		"Area            : %.2f square cm\n",
		name, colour, radius, circumference, area
	);

	delete[] name;
	delete[] colour;
}


/// \brief calculate perimeter and return
/// \param none
/// \return - float - indicate perimeter

float Circle::Perimeter(void) const
{
	return 2 * PI * radius;
}


/// \brief calculate area and return
/// \param none
/// \return - float - indicate area

float Circle::Area(void) const
{
	return PI * radius * radius;
}


/// \brief calculate dimension and return
/// \param none
/// \return - float - indicate dimension

float Circle::OverallDimension(void) const
{
	return 2 * radius;
}