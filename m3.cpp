//Filename: m3.cpp
//Project: Major 3
//Programmer: Run Ji
//First version: 10/29/2023
//Description: This is a program to calculates hotel bills for a meeting.
//				which assumes that the meeting date is Thursday and 
//				calculates the amount based on different check - in times and check - out times.

#include<stdio.h>
#include<string.h>

#define ErrorValue -1

int dayToIndex (char day[]);
double calculateCostOfRoom (const double roomRate[], int checkInDateIndex, int checkOutDateIndex);

int main()
{
	const double roomRate[6] = { 127.50, 128.25, 130.50, 150, 150, 162.50 };
	double totalCost = 0.0;
	
	for (int i = 0; i < 4; i++) //Up to four people
	{
		char name[50] = "";
		const int meetingDate = 4; //Thursday
		char checkInDate[10] = "";
		char checkOutDate[10] = "";
		int checkInDateIndex = 0;
		int checkOutDateIndex = 0;
		double currentCost = 0.0;
		
		printf("Name: ");
		fgets(name, sizeof(name), stdin); //ask to enter the name

		size_t inputNameLen = strlen(name);
		if (inputNameLen > 0 && name[inputNameLen - 1] == '\n')
		{
			name[inputNameLen - 1] = '\0'; //change the last newline character stored in the string by fgets to 0 to help 
											//with correct print blank later and comparisons
		}

		if (name[0] != '\0') //when enter name valid(not empty), then continue to ask check-in date
		{
			printf("When are they checking in: ");
			fgets(checkInDate, sizeof(checkInDate), stdin); //ask to enter check-in date
			checkInDateIndex = dayToIndex(checkInDate);

			if (checkInDateIndex != ErrorValue) //when entered check-in date are valid, then continue to ask the check-out date
			{
				printf("When are they checking out: ");
				fgets(checkOutDate, sizeof(checkOutDate), stdin); //ask to enter check-out date
				checkOutDateIndex = dayToIndex(checkOutDate);
				
				if (checkOutDateIndex != ErrorValue) //when entered check out date are valid
				{
					if (checkOutDateIndex - checkInDateIndex <= 0) //when check-out date are same as or before check-in date
					{
						printf("Error: invalid length of stay. Skipping this person.\n\n");
						continue;
					}
					else if (checkOutDateIndex < meetingDate || checkInDateIndex > meetingDate) //when entered check-out date are earlier than meeting date 
																								//or check-in date later than meeting date
					{
						printf("Error: this person is missing the meeting. Skipping this person.\n\n");
						continue;
					}
					else //normal situation, then continue to calculate the cost of this person
					{
						currentCost = calculateCostOfRoom(roomRate, checkInDateIndex, checkOutDateIndex);//current person cost
						printf("The room cost for %s is %.2f.\n\n", name, currentCost);
						totalCost += currentCost;//sum of all
					}	

				}
				else //when entered check-out date are invalid
				{
					printf("Error: invalid check-out day. Skipping this person.\n\n");
					continue;
				}	
			}
			else //when entered check-in day are invalid
			{
				printf("Error: invalid check-in day. Skipping this person.\n\n");
				continue;
			}
		}
		else //when entered invalid name
		{
			printf("Error: name missing. Skipping this person\n\n");
			continue;
		}

	} //end of loop
		
	printf("The total room cost for everyone is %.2f\n", totalCost);

	return 0;
}


//Function: dayToIndex
//Description: converts from the user input to a useful array index. Using loops and string comparisons to determine indexes
//Parameter: char day[]
//Return Value: return an int indicating the day that was entered (0 represents Sunday, 1 is Monday, etc.to 6 being Saturday)
//					or ErrorValue indicating an error, and ErrorValue is a global constant integer -1

int dayToIndex(char day[])
{
	size_t inputlen = strlen(day);
	if (inputlen > 0 && day[inputlen - 1] == '\n')
	{
		day[inputlen - 1] = '\0'; //change the last newline character stored in the string by fgets to 0 to help with comparisons
	}

	const char *days[] = { "sun", "mon", "tue", "wed", "thu", "fri", "sat" };
	for (int i = 0; i < 7; i++) 
	{
		if (strcmp(day, days[i]) == 0) 
		{
			return i;
		}
	}
	return ErrorValue;
}


//Function: calculateCostOfRoom
//Description: calculate the cost of the room. Pass in an array with the room price and pass in the check-in and check-out dates
//Parameter: const double roomRate[], int checkInDateIndex, int checkOutDateIndex
//Return Value: return the total cost for the room, as a double

double calculateCostOfRoom(const double roomRate[], int checkInDateIndex, int checkOutDateIndex)
{
	double totalCost = 0.0;

	for (int i = checkInDateIndex; i < checkOutDateIndex; i++)
	{
		totalCost += roomRate[i];
	}

	return totalCost;
}