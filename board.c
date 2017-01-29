//This is the board class to create, print, and get rid of the char double pointer board
#include "board.h"

//Creates a rectangular board of any size given the number of columns and rows
char** createBoard(int numRows, int numCols){
	char** board = (char**)malloc(numRows * sizeof(char*));
	int i, j;
	for(i = 0; i < numRows; ++i){
		board[i] = (char*)malloc(numCols * sizeof(char));
		//Fill each space with an asterisk to signal an empty space
		for(j = 0; j < numCols; ++j){
			board[i][j] = '*';
		}
	}
	return board;
}

//Print the board 
void printBoard(char** board, int numRows, int numCols){
	int i, j;
	for(i = 0; i < numRows; ++i){
		//Print the row number
		printf("%d ", numRows - 1 - i);
		for (j = 0; j < numCols; ++j){
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	//Print the column number
	printf(" ");
	for(i = 0; i < numCols; ++i){
		printf(" %d", i);
	}
	printf("\n");
}	

//Free the board 
void destroyBoard(char** board, int numRows){
	int i;
	//Free each row first as they are all char pointers
	for(i = 0; i < numRows; ++i){
		free(board[i]);
	}
	free(board);
}
