//FileName: testDisneyCharacter.cpp
//Programmer: Run Ji
//First version: 2024.01.31
//Description: 
//		Using clss, initialize two Disney characters, one for mickey and the other for minnie. 
//		then using method, change the number of movies for minnie to the number for mickey. 
//		Then show the details of the two characters. Finally try to put minnie in Epcot park.

#include "DisneyCharacter.h"

int main(void)
{
	DisneyCharacter mickey("Mickey", "1929-01-01", 100, 'M');
	DisneyCharacter minnie("Minnie", "1930-01-01");
	minnie.SameMovies(mickey);

	mickey.ShowInfo();
	printf("\n");
	minnie.ShowInfo();

	minnie.PlaceCharacter('E');
	printf("\n");

	return 0;
}