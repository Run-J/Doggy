//Filename: assign1.cpp
//Project: A-01: Overloaded Function
//Programmer: Run Ji
//First version: 01/09/2024
// Description: This program is a student grade assessment tool. 
//				Users can type 'Z' followed by a space and a file name to read grades from a file, 
//				or enter grades directly for assessment. The file or direct grade input can be a letter grade (e.g. 'A+'), 
//				a grade, or a set of assignment scores. 
//				The program parses these inputs and outputs the student's grade point or 
//				a specific situation (e.g., "Fail", "Pass", or a special case). Type 'X' to exit the program.

#include "assessGrade.h"

int main(void)
{
	char bufferUserChoice[MAXSIZECARACTERS] = ""; // make a buffer for the user's input
	while(1)
	{ 
		printf("Enter Student's Grade(s) >>> "); // prompt the user for input and receive the input
		fgets(bufferUserChoice, sizeof(bufferUserChoice), stdin); // for save user's choice
		if (bufferUserChoice[0] == 'X') // loop parse user input until the user input X
		{
			break;
		}
		else if (bufferUserChoice[0] == 'Z')
		{
			// First let's extract the filename for analyze
			char* fileName = extractFileName(bufferUserChoice);

			// Let's analyze the file
			FILE* usersFile = fopen(fileName, "r"); // open the file
			if (usersFile == NULL) // fail open the file
			{
				fprintf(stderr, "** File I/O ERROR\n");
				continue;
			}
			else // can open file
			{
				char bufferFileText[MAXSIZECARACTERS] = "";  // buffer for get text from userfile
				while (fgets(bufferFileText, sizeof(bufferFileText), usersFile) != NULL) //extract only one line per loop
				{
					char* newLine = strchr(bufferFileText, '\n');
					if (newLine != NULL)
					{
						*newLine = '\0'; // remove \n from fgets
					}
					parseUserInput(bufferFileText);
				}
				
			}

			if (fclose(usersFile) != 0)  // close the file
			{
				fprintf(stderr, "** File I/O ERROR\n");
			}
			free(fileName); // free fileName space used in extractFileName funtion.
		}

		else // normal keyboard input
		{
			parseUserInput(bufferUserChoice);
		}
	
	}

	return 0;
}