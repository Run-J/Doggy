//Filename: m2.cpp
//Project: Major 2
//Programmer: Run Ji
//First version: 10/15/2023
//Description: This program calculates power operations with base 1-25 and exponents in the range 1-5.


#include<stdio.h>
#pragma warning(disable: 4996)

int getNum(void);
int powerCalculation(int base, int exponent);
int rangeChecker(int checkValue, int minimum, int maximum);

int main()
{
	int userSelect = 0;
	int base = 1;
	int exponent = 1;

	do
	{
		printf("\n\nPower Menu\n");
		printf("\n\t1. Change base\n");
		printf("\t2. Change exponent\n");
		printf("\t3. Display base raised to exponent\n");
		printf("\t4. Exit program\n");
		printf("\nOption? ");

		userSelect = getNum();
		if (userSelect == -1)
		{
			printf("Invalid entry\n");
			continue;
		}
		if (userSelect == 1)
		{
			printf("\nChange Base: ");
			int baseUserInput = getNum();
			if (rangeChecker(baseUserInput, 1, 25) == 1)
			{
				base = baseUserInput;
			}
			else
			{
				printf("Base value is out of range!\n");
			}

		}
		else if (userSelect == 2)
		{
			printf("\nChange Exponent: ");
			int exponentUserInput = getNum();
			if (rangeChecker(exponentUserInput, 1, 5) == 1)
			{
				exponent = exponentUserInput;
			}
			else
			{
				printf("Exponent value is out of range!\n");
			}

		}
		else if (userSelect == 3)
		{
			printf("\n%d to the power of %d is %d\n", base, exponent, powerCalculation(base, exponent));
		}


	} while (userSelect != 4);

	return 0;
}




//Function:powerCalculation()
//Description: calculate the power
//Parameters: int base, int exponent
//Return values: return the result of power
int powerCalculation(int base, int exponent)
{
	int result = 1;
	int time = 0;

	for (time = 0; time < exponent; time++)
	{
		result = result * base;
	}

	return result;
}



//Function:rangeChecher()
//Description: check value whether within the range
//Parameters: int checkValue, int minimum, int maximum
//Return values: return the 1 as a value within the range or 0 as a value not within range

int rangeChecker(int checkValue, int minimum, int maximum)
{
	if (checkValue <= maximum && checkValue >= minimum)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}



//Function: getNum()
//Description: get input from the user
//Parameters: void
//Return values: return the user enterted integer or -1 as error input

int getNum(void)
{
	char record[121] = { 0 }; 
	int number = 0;
	fgets(record, 121, stdin);
	
	if (sscanf(record, "%d", &number) != 1)
	{
		/* if the user did not enter a number recognizable by
		* the system, set number to -1 */
		number = -1;
	}
	return number;
}