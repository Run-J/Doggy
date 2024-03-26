#include"Shape.h"

#ifndef _SQUAREH_
#define _SQUAREH_

/// \class Square
/// 
/// \brief This Square class is inherited from Shape. This class has a special attribute, sideLength.

class Square : public Shape
{
private:
	float sideLength;///<the sideLength of square

	static bool ValidateSideLength(float sideLength);

public:
	// constructor
	Square(char* colour, float sideLength);
	Square(void);

	// destructor
	virtual ~Square(void);

	// accessor
	float GetSideLength(void) const;

	// mutator
	int SetSideLength(float sideLength);

	// methods
	void Show(void);
	virtual float Perimeter(void) const override;
	virtual float Area(void) const override;
	virtual float OverallDimension(void) const override;
};

#endif _SQUAREH_
