#ifndef PLAY_H
	#define PLAY_H
	#include <stdbool.h>
	#include <stdio.h>
	#include <ctype.h>
	void playGame(int numRows, int numCols, int numToWin);
	int getValidPlay(int numCols);
	bool validFormat(int numArgsRead, int play, int numCols);
	void output(int player, bool won);
#endif
