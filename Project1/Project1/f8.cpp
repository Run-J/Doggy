

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


	if (strlen(argv[2]) > txtContentLenth - 1 || strlen(argv[3]) > pathLenth - 1 || strlen(argv[4]) > filenameLenth - 1) //check string arguments lenth without \0
	{
		fprintf(stderr, "Error: The argument exceeds the length limited\n");
		return 1;
	}

	strcpy(myArgs.theText, argv[2]); //copy arguments input to myArgs
	strcpy(myArgs.directoryPath, argv[3]);
	strcpy(myArgs.filename, argv[4]);