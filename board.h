#ifndef BOARD_H
	#define BOARD_H
	#include <stdio.h>
	#include <stdlib.h>
	char** createBoard(int numRows, int numCols);
	void printBoard(char** board, int numRows, int numCols);
	void destroyBoard(char** board, int numRows);
#endif
