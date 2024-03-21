#include "Shape.h"

#ifndef CIRCLEH
#define CIRCLEH

#define PI 3.1415926f

/// \class Circle
/// 
/// \brief This circle class is inherited from Shape. This class has a special attribute, radius.

class Circle : public Shape
{
private:
	float radius; ///<the radius of circle

	static bool ValidateRadius(float radius);

public:
	// constructor
	Circle(char* colour, float radius);
	Circle(void);

	// destructor
	~Circle(void);

	// accessor
	float GetRadius(void);

	// mutator
	int SetRadius(float radius);

	// methods
	void Show(void);
	float Perimeter(void) const; // calculate perimeter
	float Area(void) const override; // calculate area
	float OverallDimension(void) const override;
};

#endif CIRCLEH