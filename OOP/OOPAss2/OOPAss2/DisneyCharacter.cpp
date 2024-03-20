//
//
//
//
#include "DisneyCharacter.h"

// method name:
// parameters:
// return value:
// description:

void DisneyCharacter::SetName(string name)
{
	if (name.length() > MAXIMUMNAMECHARACTER)
	{
		this->name = name.substr(MINIMUMNAMECHARACTER, CHARACTERTRUNCATE) + "...";
	}
	else
	{
		this->name = name;
	}
}

// method name:
// parameters:
// return value:
// description:
bool DisneyCharacter::SetCreationDate(string creationDate)
{
	int year = 0;
	int month = 0;
	int day = 0;
	if (sscanf(creationDate.c_str(), "%d-%d-%d", &year, &month, &day) == 3)
	{
		this->creationDate = creationDate;
		return true;
	}
	printf("#ERROR: Invlid date format.\n");
	return false;
}


// constructors

// method name:
// parameters:
// return value:
// description:
DisneyCharacter::DisneyCharacter(string name, string creationDate, int numMovies, char whichPark)
{
	SetName(name);
	SetWhichPark(whichPark);
	SetNumMovies(numMovies);
	SetCreationDate(creationDate);
}

// method name:
// parameters:
// return value:
// description:
DisneyCharacter::DisneyCharacter(string name, string creationDate)
{
	SetName(name);
	SetCreationDate(creationDate);
	this->numMovies = 0;
	this->whichPark = 'N';
}

// deconstructor

// method name:
// parameters:
// return value:
// description:
DisneyCharacter::~DisneyCharacter()
{
	printf("%s destroyed\n", name.c_str());
}


// accessors

// method name:
// parameters:
// return value:
// description:
string DisneyCharacter::GetName(void)
{
	return name;
}

// method name:
// parameters:
// return value:
// description:
string DisneyCharacter::GetCreationDate(void)
{
	return creationDate;
}

// method name:
// parameters:
// return value:
// description:
int DisneyCharacter::GetNumMovies(void)
{
	return numMovies;
}

// method name:
// parameters:
// return value:
// description:
char DisneyCharacter::GetWhichpark(void)
{
	return whichPark;
}


// mutator

// method name:
// parameters:
// return value:
// description:
bool DisneyCharacter::SetNumMovies(int numMovies)
{
	if (numMovies >= MINIMUMNUMOFMUVIES)
	{
		this->numMovies = numMovies;
		return true;
	}
	else
	{
		this->numMovies = 0;
		return false;
	}
}

// method name:
// parameters:
// return value:
// description:
bool DisneyCharacter::SetWhichPark(char whichPark)
{
	switch (whichPark)
	{
	case 'M':
	case 'S':
	case 'A':
	case 'E':
	case 'C':
	{
		this->whichPark = whichPark;
		string parkName = parkFullName(whichPark);
		printf("The character is assigned to the %s park\n", parkName.c_str());
		return true;
	}
	default:
		printf("Character not placed\n");
		this->whichPark = 'N';
		return false;
	}
}

// method name:
// parameters:
// return value:
// description:
void DisneyCharacter::ShowInfo(void)
{
	printf("Character Name: %s\n", this->name.c_str());
	printf("Creation Date: %s\n", this->creationDate.c_str());
	printf("Number of movies that the character has been in: %d\n", this->numMovies);
	string parkName = parkFullName(this->whichPark);
	printf("Which of the DisneyWorld / DisneyLand parks the character can be found in: %s\n", parkName.c_str());
}

// method name:
// parameters:
// return value:
// description:
bool DisneyCharacter::PlaceCharacter(char whichPark)
{
	return SetWhichPark(whichPark);
}

// method name:
// parameters:
// return value:
// description:
void DisneyCharacter::SameMovies(DisneyCharacter& anotherCharacter)
{
	SetNumMovies(anotherCharacter.GetNumMovies());
}

// function name: parkFullName
// parameters: char ParkAbbrevations - M, S, A, E, C, N indicate the which parks the character can be found in
// return value: string - park fullname
// description: enter the abbreviation of a park and return the full name of the corresponding park for show infomation

string parkFullName(char ParkAbbre)
{
	string parkFullName;
	switch (ParkAbbre)
	{
	case 'M':
	{
		parkFullName = "Magic Kingdom";
		return parkFullName;
	}
	case 'S':
	{
		parkFullName = "Disney Studios";
		return parkFullName;
	}
	case 'A':
	{
		parkFullName = "Animal Kingdom";
		return parkFullName;
	}
	case 'E':
	{
		parkFullName = "Epcot";
		return parkFullName;
	}
	case 'C':
	{
		parkFullName = "California Adventure";
		return parkFullName;
	}
	default:
		parkFullName = "Not placed";
		return parkFullName;
	}
}


