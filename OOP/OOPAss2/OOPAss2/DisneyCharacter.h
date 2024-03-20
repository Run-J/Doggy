#pragma once

#include<stdio.h>
#include<string>
#pragma warning(disable:4996)

#define MAXIMUMNAMECHARACTER 50
#define MINIMUMNAMECHARACTER 0
#define CHARACTERTRUNCATE 46
#define MINIMUMNUMOFMUVIES 0

using namespace std;

string parkFullName(char ParkAbbre);  // This is a function prototype I wrote myself 
									 // to turn the park shorthand into the full park name for outputting information 
									// in a way that makes it easier for the user to understand.

// Class Name: DisneyCharacter
// Class purpose: balbalabala..... 

class DisneyCharacter
{
private:
	string name; //....
	string creationDate; //....
	int numMovies; //....
	char whichPark; //....

	void SetName(string name);
	bool SetCreationDate(string creationDate);
	
public:
	DisneyCharacter(string name, string creationDate, int numMovies, char whichPark);
	DisneyCharacter(string name, string creationDate);
	~DisneyCharacter();

	// accessors
	string GetName(void);
	string GetCreationDate(void);
	int GetNumMovies(void);
	char GetWhichpark(void);

	// mutator
	bool SetNumMovies(int numMovies);
	bool SetWhichPark(char whichPark);
	void ShowInfo(void);
	bool PlaceCharacter(char whichPark);
	void SameMovies(DisneyCharacter& anotherCharacter);

};
