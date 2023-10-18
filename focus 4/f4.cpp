//Filename:f4.cpp
//Project: Focused 
//Programmer: Run Ji 8874457
//First version: 10/10/2023
//Description: Get the ten integers entered by the user and store them in an array, then check the mininum number and index.

#include<stdio.h>
int getNum(void);

int main(void)
{	
	int time = 0;
	int number = 0;
	int butter[10] = { 0 };
	int lowestIndex = 0;
	int lowestValue = 0;

	for (time = 0; time <= 9; time++)
	{
		printf("Please input the value at index %d in the array: ", time);
		int number = getNum();
		butter[time] = number;
		
	
		if (time == 0 || number < lowestValue)
		{
			lowestValue = number;
			lowestIndex = time;
		}

	}

	printf("\nThe lowest value is %d at index %d\n", lowestValue, lowestIndex);
	
	return 0;
}


//Function:getNum()
//Description : get input from the user
//Parameters : void
//Return values : return the user enterted integer

#pragma warning(disable: 4996)
int getNum(void)
{
	char record[100] = { 0 };
	int number = 0;
	fgets(record, 100, stdin);
	sscanf(record, "%d", &number);

	return number;
} // end getNum()

int currentIndex = 0;
int value = 0;
int lowestIndex = 0;
int lowestValue = 0;


for (currentIndex = 0; currentIndex <= size - 1; currentIndex++)
{
	value = array[currentIndex];
	if (currentIndex == 0 || value < lowestValue)
	{
		lowestValue = value;
		lowestIndex = currentIndex;
	}

}