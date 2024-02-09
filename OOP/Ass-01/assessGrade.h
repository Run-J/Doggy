//Filename: assessGrade.h
//Project: A-01: Overloaded Function
//Programmer: Run Ji
//First version: 01/09/2024
// Description: This header file contains several function prototypes and preprocessing instructions

#pragma once
#pragma warning (disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FALSE -1
#define SUCCESS 0
#define MAXSIZECARACTERS 101
#define FIVEASSIGNMENT 5
#define MAXIMUMMARK 100.00
#define MINIMUMMARK 0.00
#define PASSMARK 55.50

typedef struct
{
	const char* grade;
	const char* decription;
	double percentage;
}charGradeDescription;

char* extractFileName(char* userInput);
int parseUserInput(char* userInput);
void assessGrade(double userInput);
int assessGrade(int unserInput[FIVEASSIGNMENT]);
int assessGrade(char* userInput);
