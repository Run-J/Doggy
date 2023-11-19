//Filename: f6.cpp
//Project: Focus 6
//Programmer: Run Ji
//First version: 11/6/2023
//Description: create some functions that utilize pointer skills to get user input, calculate the average, and the sum

#include<stdio.h>
#pragma warning (disable:4996)

#define sevenDoubles 7
#define fourFloat 4
#define fourPrompt 4

int getDouble(double* pNumber);
void calculateStats(double d1, double d2, double d3, double d4, double* pAverage, double* pSum);
void calculateArrayStats(double values[], int numArray, double* pSum, double* pAverage);
void fillArray(double values[], int numArray, double fillValue);


int main()
{
		double d1 = 0;
		double d2 = 0;
		double d3 = 0;
		double d4 = 0;
		double* input[fourFloat] = { &d1, &d2, &d3, &d4 }; 

		//Due to calculateStat function's parameter is d1,d2,d3,d4, not pointer(array)
		//At this point the address is stored in the array, making it easier to change d1, d2, etc.itself later.
		// If I don't store the address, but the d1 and d2 themselves, it will be copies, 
		// and even if the elements in the input array are changed, the d1 and d2 themselves will still be 0.00.
		const char* promptUser[fourPrompt] = { "Enter a floating point number: ", 
			"Enter another floating point number: ",
			"Enter another floating point number: ",
			"Enter another floating point number: " };

		for (int i = 0; i < fourPrompt; i++) //get four inputs
		{
			printf("%s", promptUser[i]); //prompt the user
			if (getDouble(input[i]) != 1) //check for validity, if != 1 means not valid input
											//input[i] use to store in the array "input"
			{
				return 0; //exit program if not valid
			}
		}

		double average = 0;
		double sum = 0;

		calculateStats(d1, d2, d3, d4, &average, &sum);
		printf("The average and sum of the variables: %f %f\n", average, sum);

		double values[sevenDoubles] = { 0 };
		
		for (int i = 0; i < sevenDoubles; i++)
		{
			printf("Enter a number: ");
			if (getDouble(&values[i]) != 1)//check validity and take user input fill in the array value
			{
				return 0;
			}
		}

		calculateArrayStats(values, sevenDoubles, &sum, &average);
		printf("The average and sum of the array elements: %f, %f\n", average, sum);
		
		fillArray(values, sevenDoubles, 40);
		for (int i = 0; i < sevenDoubles; i++)
		{
			printf("%f", values[i]);
			if (i < sevenDoubles-1)//final nuimber does not have a comma after it
			{
				printf(",");
			}
		}
		printf("\n");

	return 0;
}


//Function: getDouble()
//Parameter : double* pNumber : pointer to a variable that is filled in by the user input, if valid
//Return Value : int : 1 if the user entered a valid floatingpoint number, 0 otherwise
//Description : This function gets a floating - point number
//				from the user.If the user enters a valid floating - point
//				number, the value is put into the variable pointed to by
//				the parameter and 1 is returned.If the user - entered value
//				is not valid, 0 is returned.

int getDouble(double* pNumber)
{
	char buffer[50];
	if (fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		if (sscanf(buffer, "%lf", pNumber) == 1)
		{
			return 1;
		}

	}
	return 0;
}


//Function: calculateStats()
//Parameters : double d1, d2, d3, d4, double* pAverage : pointer to a variable that is filled in by this function with the average of d1, d2,
//				d3, and d4 double* pSum : pointer to a variable that is filled in by this function with the sum of d1, d2, d3, and d4
//Return Value : none
//Description : This function takes four floating - point numbers passed as doubles and calculates the average and
//				sum of the numbers.Once calculated, the average gets put into the variable pointed to by the pAverage parameter and
//				the sum gets put into the variable pointed to by the pSum parameter.

void calculateStats(double d1, double d2, double d3, double d4, double* pAverage, double* pSum) 
{
	*pSum = d1 + d2 + d3 + d4;
	*pAverage = *pSum / 4;
}


//Function: calculateArrayStats()
//Parameters : double values[] : floating - point numbers
//				int numArray : number of array elements
//				  double* pSum : pointer to a variable that is filled in by this function with the sum of all elements in the array
//					double* pAverage : pointer to a variable that is filled in by this function with the average of all elements in the array
//Return Value : none
//Description : This function takes an array of floating - point
//					(double) numbers, given the number of elements in the array
//						as a parameter, and calculates the average and sum of the
//							numbers.Once calculated, the average gets put into the
//								variable pointed to by the pAverage parameter and the sum
//									gets put into the variable pointed to by the pSum parameter.

void calculateArrayStats(double values[], int numArray, double* pSum, double* pAverage)
{
	*pSum = 0;

	for (int i = 0; i < numArray; i++) 
	{
		*pSum += values[i];
	}
	*pAverage = *pSum / numArray;
}


//Function: fillArray()
//Parameters : double values[] : floating - point numbers
//				int numArray : number of array elements
//			 	 double fillValue : value to put into array elements
//Return Value : none
//Description : This function takes an array of floating - point
//				(double) numbers, given the number of elements in the array
//				as a parameter, and puts the fillValue into each element of
//				the array.

void fillArray(double values[], int numArray, double fillValue)
{
	for (int i = 0; i < numArray; i++)
	{
		values[i] = fillValue;
	}
}

