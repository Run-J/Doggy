//Filename: f8.cpp
//Project: Focus 8
//Programmer: Run Ji
//First version: 11/19/2023
//Description: Users can enter the text they want to store, the number of times they want to store it, and the path to store it.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma warning (disable:4996)

#define txtContentLenth 21
#define pathLenth 21
#define filenameLenth 21

struct MyData
{
	int HowMany;
	char theText[txtContentLenth];
	char directoryPath[pathLenth];
	char filename[filenameLenth];
};

int main(int argc, char* argv[])
{
	if (argc != 5) //check how many arguments are on the command line
	{
		fprintf(stderr, "Error: Not four arguments.\n");
		return 1;
	}


	struct MyData myArgs = { 0,"","","" };
	myArgs.HowMany = atoi(argv[1]);
	if (myArgs.HowMany <= 0) //check first argument whether > 0
	{
		fprintf(stderr, "Error: The first argument should be positive integer.\n");
		return 1;
	}

	
	if (strlen(argv[2]) > txtContentLenth-1 || strlen(argv[3]) > pathLenth-1 || strlen(argv[4]) > filenameLenth-1) //check string arguments lenth without \0
	{
		fprintf(stderr, "Error: The argument exceeds the length limited\n");
		return 1;
	}

	strcpy(myArgs.theText, argv[2]); //copy arguments input to myArgs
	strcpy(myArgs.directoryPath, argv[3]);
	strcpy(myArgs.filename, argv[4]);

	char fullLocation[pathLenth + filenameLenth-1] = "";
	sprintf(fullLocation, "%s\\%s", myArgs.directoryPath, myArgs.filename); //variable to contain the full location of the file

	FILE* txtfp = fopen(fullLocation, "w");
	if (txtfp == NULL)
	{
		fprintf(stderr, "Error: Failed to open the file\n");
		return 1;
	}

	for (int i = 0; i < myArgs.HowMany; i++)
	{
		if (fprintf(txtfp, "%s\n", myArgs.theText) < 0)
		{
			fprintf(stderr, "Error: Failed write to the file\n");
			return 1;
		}
	}

	if (fclose(txtfp) != 0)
	{
		fprintf(stderr, "Error: Failed to close the File\n");
	}

	return 0;
}