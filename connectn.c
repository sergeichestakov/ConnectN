/*
Sergei Chestakov
ECS 30
This program simulates a Connect 4 like game in which 2 players play on any size board they want an connect an inputted, n, amount of pieces horizontally, vertically, or diagnally to win
*/
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "play.h"
#include "endconditions.h"

void checkArgs(int argc);

int main(int argc, char *argv[]){
	checkArgs(argc);
	//Assign inputted values to integer variables by converting them
	int numRows = atoi(argv[1]);
	int numCols = atoi(argv[2]);
	int numToWin = atoi(argv[3]);
	//Play the game
	playGame(numRows, numCols, numToWin);
	return 0;
}

//Check to make sure there are the exact amount of required arguments (4)
void checkArgs(int argc){
	if(argc < 4){
		printf("Not enough arguments entered\nUsage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(0);
	}
	if(argc > 4){
		printf("Too many arguments entered\nUsage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(0);
	}
}
