//Filename: f7.cpp
//Project: Focus 7
//Programmer: Run Ji
//First version: 11/12/2023
//Description: This is a program that demonstrates how to create txt and binary files, and how to write the data

#include<stdio.h>

#pragma warning (disable:4996)


int main()
{
	//create a .txt file and input two lines

	FILE* txtfp = fopen("myTextFile.txt", "w");
	if (txtfp == NULL)
	{
		fprintf(stderr, "Error: Failed to open myText.txt\n");
		return 1;
	}
	if (fprintf(txtfp, "This is line 1.\nThis is line 2.") < 0)
	{
		fprintf(stderr, "Error: Failed to write to myText.txt\n");
		return 1;
	}
	if ( fclose(txtfp) != 0 )
	{
		fprintf(stderr, "Error: Failed to close the myBinaryFile.data\n");
	}


	//create a .data file and input some data

	const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };
	size_t dataLen = sizeof(kBinaryData) / sizeof(kBinaryData[0]); // count how many integer it array has for checking error

	FILE* datafp = fopen("myBinaryFile.data", "wb");
	if (datafp == NULL)
	{
		fprintf(stderr, "Error: Failed to open myBinaryFile.data\n");
		return 1;
	}
	if (fwrite(kBinaryData, sizeof(kBinaryData[0]), dataLen, datafp) != dataLen)
	{
		fprintf(stderr, "Error: Failed to write to myBinaryFile.data\n");
		return 1;
	}
	if (fclose(datafp) != 0)
	{
		fprintf(stderr, "Error: Failed to close the myBinaryFile.data\n");
	}


	return 0;
}