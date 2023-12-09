//Filename: m4.cpp
//Project: Major 4
//Programmer: Run Ji
//First version: 11/23/2023
// Description: 
//     This program is designed to analyze and process game results for multiple teams.
//     It reads the file 'teams.txt', which contains the file paths to individual team result files.
//     For each team, the program opens its result file, reads the game outcomes, and computes the
//     team's season statistics, including total wins, losses, ties, and the winning percentage.
//     The results are then formatted and output to the console. 
//     Note: The program currently supports processing up to 20 teams and 20 games per team.
//     To process more teams or games, adjust the HOW_MANY_TEAMS and GameTimes macros accordingly.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

#define GameTimes 20  // Max games to process per team. Change as needed for more games.
#define MaxLineSize 41	//No line is longer than 40 characters
#define HowManyTeams 20 // Max number of teams to process. Change as needed for more teams.


//Function prototypes
int parseLine(char* gameResult, char* oppoenentName, int* primaryScore, int* opponentScore);
int processGames(char* filename);


//Main function
int main(void)
{
	FILE* fpteams = fopen("teams.txt", "r");
	if (fpteams == NULL)
	{
		fprintf(stderr, "teams file opening failed");
		return -1;
	}

	for (int i = 0; i < HowManyTeams; i++)
	{
		char GameResultFile[MaxLineSize] = "";
		if (fgets(GameResultFile, sizeof(GameResultFile), fpteams) == NULL)
		{
			break;
		}
		//Now is first loop for fgets, only get first line of teams.txt (Toronto Maple Leafs.txt ),
		//when second loop, that will get second line of teams.txt (NewYorkYankees.txt ),
		//BUT include '\n', following will remove '\n'; In addtion, GameResultFile use to indicate file path
		char* newline = strchr(GameResultFile, '\n');
		if (newline)
		{
			*newline = '\0';
		}

		printf("Processing %s:\n", GameResultFile);
		processGames(GameResultFile);
	}

	if (fclose(fpteams) != 0)
	{
		fprintf(stderr, "Error: Failed to close the teams file\n");
		return -1;
	}

	return 0;
}



// Function: parseLine
// Parameters: 
//		char* gameResult - A string containing the game results and team names.
//		char* opponentName - A string buffer where the opponent's name will be stored.
//		int* primaryScore - Pointer to an int where the primary team's score will be stored.
//		int* opponentScore - Pointer to an int where the opponent's score will be stored.
// Return Value: 
//		Returns 0 to indicate successful execution, -1 to indicate an error occurred.
// Description:
//		This function parses a game result string in the format "TeamName,Score-Score".
//		It extracts the opponent's name, primary team's score, and opponent's score from the string.
//		The opponent's name is copied into the opponentName buffer,
//		and the scores are converted from strings to integers and stored in the provided int pointers.

int parseLine(char* gameResult, char* opponentName, int* primaryScore, int* opponentScore)
{
	char* dash = strchr(gameResult, '-'); //position of -
	char* comma = strchr(gameResult, ','); //position of ,
	if (!dash || !comma) 
	{
		return -1; 
	}
	int opponentNameLenth = comma - gameResult; //opponent name's lenth

	strncpy(opponentName, gameResult, opponentNameLenth); 
	opponentName[opponentNameLenth] = '\0';
									//gameResult example: NewYorkYankees,4-5
	*primaryScore = atoi(comma + 1); //pointer of  comma + 1 is 4
	*opponentScore = atoi(dash + 1); //pointer of dash + 1 is 5

	return 0;
}



// Function: processGames
// Parameter:
//		char* filename - A string representing the filename of the game results to be processed.
// Return Value:
//		Returns 0 for successful execution, -1 for any errors encountered.
// Description:
//		This function processes a file containing game results, where the filename is provided by 'filename'.
//		It attempts to open the file first and returns an error if this fails.
//		The function then reads the file line by line, each representing a game's result, and uses the parseLine function to parse these results.
//		It keeps count of wins, losses, and ties, and finally calculates the winning percentage.
//		The results of each game are formatted and outputted. The file is closed at the end of the function and the execution status is returned.

int processGames(char* filename)
{
	FILE* fpGameResult = fopen(filename, "r");
	if (fpGameResult == NULL)
	{
		fprintf(stderr, "filename file opening failed\n");
		return -1;
	}

	char gameResult[MaxLineSize] = "";
	char primaryName[MaxLineSize] = "";
	int wins = 0;
	int loses = 0;
	int ties = 0;
	strncpy(primaryName, filename, strstr(filename, ".txt") - filename); //primaryName equal filename without the suffix
	for (int i = 0; i < GameTimes; i++)
	{
		if (fgets(gameResult, sizeof(gameResult), fpGameResult) == NULL) //first loop get first game, second loop get second game and so on
		{
			break;
		}

		char opponentName[MaxLineSize];
		int primaryScore = 0;
		int opponentScore = 0;
		if (parseLine(gameResult, opponentName, &primaryScore, &opponentScore) != 0) //parse the game line
		{
			fprintf(stderr, "\tError parsing the this game result line\n");
			continue; //Skip the current game and continue processing the next game.
		}

		if (primaryScore > opponentScore)
		{
			printf("\t%s beat %s %d - %d\n", primaryName, opponentName, primaryScore, opponentScore);
			wins++;
		}
		else if (primaryScore == opponentScore)
		{
			printf("\t%s and %s tied at %d\n", primaryName, opponentName, primaryScore);
			ties++;
		}
		else if (primaryScore < opponentScore)
		{
			printf("\t%s lost to %s %d - %d\n", primaryName, opponentName, primaryScore, opponentScore);
			loses++;
		}

	}

	// Calculate and print the winning percentage
	float winningPercentage = (2.0 * wins + ties) / (2.0 * (wins + loses + ties));
	printf("Season result for %s: %0.3f (%d-%d-%d)\n\n", primaryName, winningPercentage, wins, loses, ties);

	if (fclose(fpGameResult) != 0)
	{
		fprintf(stderr, "%s file opening failed\n", filename);
		return -1;
	}

	return 0;
}