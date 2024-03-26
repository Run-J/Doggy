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
	virtual ~Circle(void);

	// accessor
	float GetRadius(void);

	// mutator
	int SetRadius(float radius);

	// methods
	void Show(void);
	virtual float Perimeter(void) const; // calculate perimeter
	virtual float Area(void) const override; // calculate area
	virtual float OverallDimension(void) const override;
};

#endif CIRCLEH