//Filename:f5.cpp
//Project: Focused 5
//Programmer: Run Ji  8874457
//First version: 10/16/2023
//Description:  Use a function to get the ten integers entered by the user and store them in an array, 
//					then use another function to check the minimum number and figure out index. 


#include<stdio.h>
#pragma warning(disable: 4996)

int getNum(void);
void modifyArrayValues(int array[], int size);
int minArrayValue(int array[], int size);

#define ksizeOfArray 10

int main(void)
{	
	int butter[ksizeOfArray] = { 0 };
	int lowestIndex = 0;
	int lowestValue = 0;

	modifyArrayValues (butter, ksizeOfArray); //get values from user
	lowestIndex = minArrayValue(butter, ksizeOfArray); //figure out the lowest index
	lowestValue = butter[lowestIndex];
	
	printf("\nThe lowest value is %d at index %d\n", lowestValue, lowestIndex);

	return 0;
}


//Function: getNum()
//Description: get input from the user
//Parameters: void
//Return values: return the user enterted integer

int getNum(void)
{
	char record[100] = { 0 };
	int number = 0;
	fgets(record, 100, stdin);
	if (sscanf(record, "%d", &number) != 1)
	{
		number = -1;
	}

	return number;
} 


//Function: modifyArrayValues()
//Description: prompts user and get values for all of the array elements
//Parameters: int array[], int size
//Return values: void

void modifyArrayValues(int array[], int size)
{
	int time = 0;
	int number = 0;

	for (time = 0; time < size; time++)
	{
		printf("Please input the value at index %d in the array: ", time);
		int number = getNum();
		array[time] = number;
	}

}


//Function: minArrayValue()
//Description: loops through the array and figuring out which element has the lowest value.
//Parameters: int array[], int size
//Return values: lowestIndex

int minArrayValue(int array[], int size)
{
	int currentIndex = 0;
	int lowestIndex = 0;

	for (currentIndex = 1; currentIndex <= size-1; currentIndex++)
	{

		if (array[currentIndex] < array[lowestIndex])
		{
			lowestIndex = currentIndex;
		}

	}
	
	return lowestIndex;
}
