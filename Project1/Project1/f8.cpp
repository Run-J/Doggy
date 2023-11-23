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
