//Filename:f3.cpp
//Project: Focused 3
//Programmer: Run Ji
//First version: 09/25/2023
//Description: This function use to get a number from the user and displays whether the number is even or odd. 

#include<stdio.h>
int getNum(void);
int isOdd(int number);

int main(void)
{
	int number = 0;

	printf("Enter a non-negative number: ");
	number = getNum();

	if (isOdd(number))
	{
		printf("%d is odd\n", number);
	}
	else
	{
		printf("%d is even\n", number);
	}
	return 0;
}


//Function:isOdd()
//Description : determine whether the number is odd or even
//Parameters : int number
//Return values : ture(1) or false(0)

int isOdd(int number)
{
	if (number % 2 != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
} // end isOdd()


//Function:getNum()
//Description : get input from the user
//Parameters : void
//Return values : return the user enterted integer or -1

#pragma warning(disable: 4996)
int getNum(void)
{
	char record[121] = { 0 };
	int number = 0;
	fgets(record, 121, stdin);

	if (sscanf(record, "%d", &number) != 1)
	{
		number = -1;
	}
	return number;
} // end getNum()
