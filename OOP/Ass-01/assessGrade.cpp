//Filename: assessGrade.cpp
//Project: A-01: Overloaded Function
//Programmer: Run Ji
//First version: 01/09/2024
// Description: This file contains some function details.

#include"assessGrade.h"


// Function: extractFileName
// Parameter: char* userInput - A string that includes the user's input, starting with 'Z' followed by a file name.
// Return Value: Returns a pointer to a dynamically allocated string containing the extracted file name.
// Description:
//				This function extracts the file name from the user's input, 
//				which is expected to start with 'Z' followed by the actual file name.
//				It allocates memory dynamically to store the file name and returns this memory address.
//				The function skips the first two characters ('Z' and a space), 
//				then copies the rest of the input into the allocated space, stopping at the newline character.
//				The caller is responsible for freeing the allocated memory.

char* extractFileName(char* userInput)
{
	//let's extract the file name

		//The first way I can use strcpy in the strlib.h

		//char fileName[MAXSIZECARACTERS] = "";
		//strcpy(fileName, userInput + 2); // start after space that followed by Z
		//for (int i = 0; fileName[i] != '\0'; i++)
		//{
		//	if (fileName[i] == '\n') // the place before \0 is \n
		//	{
		//		fileName[i] = '\0'; // remove \n from fgets
		//		break;
		//	}
		//}

		//below is second way to write a copy like strcpy's function, I want to try something I just leared

	char* fileName = (char*)malloc(MAXSIZECARACTERS * sizeof(char)); //there like make a char array 
	if (fileName == NULL) // check error if created a space sccuessfully
	{
		fprintf(stderr, "Memory allocation didn't success\n");
		exit(FALSE);
	}
	char* temp = fileName;
	char* fileNameUserInput = userInput + 2; // start after space that followed by Z
	while (*fileNameUserInput != '\n') // remove the \n from the fgets
	{
		*temp = *fileNameUserInput;
		temp++;
		fileNameUserInput++;
	}
	*temp = '\0'; // add a '\0' to give my string the correct ending and avoid to appear some random data

	return fileName;
}



// Function: parseUserInput
// Parameter:
//			char* buffer - A string containing the user's input, which can be a double, a string, or an array of integers.
// Return Value:
//			Returns 0 after successful execution, indicating no errors occurred.
// Description:
//			This function analyzes the user's input and determines its type: 
//			a double (single grade), an array of integers (multiple grades), or a string (letter grade or special situation). 
//			It uses sscanf to parse the input. If the input contains no spaces, it's treated as a double. 
//			If there are spaces, it's treated as an array of integers. 
//			Otherwise, it's processed as a string. 
//			After parsing, it calls the appropriate assessGrade function for further evaluation.

int parseUserInput(char* buffer)
{
	double doubleGrades = 0;
	char strGrades[MAXSIZECARACTERS] = "";
	int intGrades[FIVEASSIGNMENT] = { 0 };

	// if the buffer has no spaces, it means this is only a double representing the final mark.
	if (sscanf(buffer, "%lf", &doubleGrades) != 0 && strchr(buffer, ' ') == NULL)
	{
		assessGrade(doubleGrades);
	}
	// if the buffer has spaces, it means that the input is an array.
	else if (strchr(buffer, ' ') != NULL)
	{
		// reset the intGrades array to 0 second time use it array
		// delete old grades to re-store the new assignment grades
		memset(intGrades, 0, sizeof(intGrades));
		int numRead = 0;
		int offset = 0;
		int n = 0;
		while (numRead < FIVEASSIGNMENT && sscanf(buffer + offset, "%d%n", &intGrades[numRead], &n) == 1)
		{
			numRead++;
			offset = offset + n;
		}
		assessGrade(intGrades);
	}
	else // user input is character, like A+, B, DNA
	{
		if (sscanf(buffer, "%s", strGrades) != 0)
		{
			assessGrade(strGrades);
		}
	}

	return 0;
}



// Function: assessGrade(int userInput[FIVEASSIGNMENT]
// Parameter:
//			int userInput[FIVEASSIGNMENT] - An array of integers representing grades for five(MAXIMUM) assignments.
// Return Value:
//			int, FALSE indicate invalid input
// Description:
//			Calculates the average of five assignment grades. 
//			Grades averaging 54.50 or higher result in a pass, while averages below 54.50 are a fail. 
//			Outputs the student's average grade and pass/fail status. 
//			Generates an error message for invalid grade inputs. Or, return FALSE if input > 100 or input < 0

int assessGrade(int userInput[FIVEASSIGNMENT])
{
	float sum = 0;
	for (int i = 0; i < FIVEASSIGNMENT; i++)
	{
		if (userInput[i] < 0 || userInput[i] > 100)
		{
			fprintf(stderr, "**ERROR : Invalid Input\n");
			return FALSE;
		}
		sum = sum + userInput[i];
	}

	sum = sum / FIVEASSIGNMENT; // each of five assignments worth 20% each,
	assessGrade(sum);

	return 0;
}


//Function: assessGrade(char* userInput)
//Parameter: 
//		userInput - Pointer to a string representing the grade.
// Return Value: 
//		SUCCESS (defined as 0 or another success indicator) if a valid grade description is found.
//		If the grade is invalid, prints an error message and returns an error code.
//Description:  This function looks up a description for the input grade string (such as "A+", "B", etc.)
//				using an array of charGradeDescription type, which stores grades and their corresponding descriptions.
//				If a matching grade is found, it prints the description of that grade.
//				If the input grade is not in the predefined list, it prints an error message.
//				The function is designed to evaluate standard grades as well as special situations(like "I", "Q").

int assessGrade(char* userInput)
{
	charGradeDescription description[]=
	{
		{"A+", "", 95.00},
		{"A", "", 85.00},
		{"B+", "", 77.00},
		{"B", "", 72.00},
		{"C+", "", 67.00},
		{"C", "", 62.00},
		{"D", "", 57.00},
		{"F", "", 50.00},
		// special situations
		{"I", "Student has Special Situation : I (Incomplete.)\n", 0},
		{"Q", "Student has Special Situation : Q (Withdrawal After Drop/Refund Date.)\n", 0},
		{"AU", "Student has Special Situation : AU (Audit Condition.)\n", 0},
		{"DNA", "Student has Special Situation : DNA (Did Not Attend.)\n", 0},
		{"I/P", "Student has Special Situation : I/P (In Process.)\n", 0},
		// end sign
		{"", NULL, 0}
	};

	for (int i = 0; description[i].grade != ""; i++)
	{
		if (strcmp(description[i].grade, userInput) == 0)
		{
			if (strcmp(userInput, "I") == 0 || strcmp(userInput, "Q") == 0 ||
			    strcmp(userInput, "AU") == 0 || strcmp(userInput, "DNA") == 0 ||
			    strcmp(userInput, "I/P") == 0)
			{
			printf("%s", description[i].decription);
			}
			else
			{
			assessGrade(description[i].percentage);
			}
			return SUCCESS;
		}
	}

	fprintf(stderr, "**ERROR: Invalid Input\n");
	return 0;
}


// Function: assessGrade(double userInput)
// Parameter:
//			double userInput - A numerical grade value.
// Return Value:
//			void
// Description:
//			Evaluates a student's numerical grade. 
//			Grades 54.50 and above are deemed a pass, while grades below 54.50 are a fail. 
//			The function prints the student's achievement status based on this criterion. 
//			For invalid input outside the 0.0 to 100.0 range, it displays an error message.

void assessGrade(double userInput)
{
	if (userInput >= PASSMARK && userInput <= MAXIMUMMARK)
	{
		printf("Student achieved %.2lf %% which is a PASS condition.\n", userInput);
	}
	else if (userInput < PASSMARK && userInput >= MINIMUMMARK)
	{
		printf("Student achieved %.2lf %% which is a FAIL condition.\n", userInput);
	}
	else
	{
		fprintf(stderr, "**ERROR : Invalid Input\n");
	}
}
