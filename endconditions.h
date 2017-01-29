#ifndef ENDCONDITIONS_H
	#define ENDCONDITIONS_H
	#include <stdbool.h>
	#include <stdlib.h>
	bool gameOver(char** board, int numRows, int numCols, int numToWin);
	bool gameWon(char** board, int numRows, int numCols, int numToWin);
	bool rowWin(char** board, int numRows, int numCols, int numToWin);
	bool colWin(char** board, int numRows, int numCols, int numToWin);
	bool diagWin(char** board, int numRows, int numCols, int numToWin);
	bool rightDiagWin(char** board, int numRows, int numCols, int numToWin);
	bool leftDiagWin(char** board, int numRows, int numCols, int numToWin);
	bool tied(char** board, int numRows, int numCols);
#endif
	
