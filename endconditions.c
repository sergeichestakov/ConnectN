#include "endconditions.h"

//Returns whether the game is over or not based on if it was won or tied
bool gameOver(char** board, int numRows, int numCols, int numToWin){
	if (gameWon(board, numRows, numCols, numToWin) || tied(board, numRows, numCols)){
		return true;
	}
	return false;
}

//Returns if the game was won or not
bool gameWon(char** board, int numRows, int numCols, int numToWin){
	return rowWin(board, numRows, numCols, numToWin) || colWin(board, numRows, numCols, numToWin) || diagWin(board, numRows, numCols, numToWin);
}

//Returns if the game was won horizontally
bool rowWin(char** board, int numRows, int numCols, int numToWin){
	if(numToWin > numCols){
		return false;
	}
	int i, j, n;
	//For each row in the board
	for(i = 0; i < numRows; ++i){
		//Check each column wthin index
		for(j = 0; j <= numCols - numToWin; ++j){
			char firstPiece = board[i][j];
			//If the piece is empty, move on
			if(firstPiece == '*'){
				continue;
			}
			//Otherwise check to see if the first piece equals all of the numToWin pieces to the right
			for(n = 1; n < numToWin; ++n){
				if(firstPiece != board[i][j+n]){
					goto keepChecking;
				}	
			}
			return true;
			keepChecking:;
		}
	}
	return false;
}

bool colWin(char** board, int numRows, int numCols, int numToWin){
	if(numToWin > numRows){
		return false;
	}
	int i, j, n;
	//For each column in the board
	for(i = 0; i < numCols; ++i){
		//Check each row wthin index
		for(j = 0; j <= numRows - numToWin; ++j){
			char firstPiece = board[j][i];
			//If the piece is empty, move on
			if(firstPiece == '*'){
				continue;
			}
			//Otherwise check to see if the first piece equals all of the numToWin pieces below it
			for(n = 1; n < numToWin; ++n){
				if(firstPiece != board[j+n][i]){
					goto keepChecking;
				}	
			}
			return true;
			keepChecking:;
		}
	}
	return false;
}

//Return if the game was won diagnally in one of two ways, right or left (see below)
bool diagWin(char** board, int numRows, int numCols, int numToWin){
	if(numToWin > numCols || numToWin > numRows){
		return false;
	}
	return rightDiagWin(board, numRows, numCols, numToWin) || leftDiagWin(board, numRows, numCols, numToWin);
}

//Start at the bottom left corner of the array and check up diagnally
bool rightDiagWin(char** board, int numRows, int numCols, int numToWin){
	int row, col, n;
	for(row = numRows - 1; row >= numRows - numToWin; --row){
		for(col = 0; col <= numCols - numToWin; ++col){
			char firstPiece = board[row][col];
			if(firstPiece == '*'){
				continue;
			}
			for(n = 1; n < numToWin; ++n){
				if(row - n < 0){
					goto keepChecking;			
				}
				if(firstPiece != board[row - n][col + n]){
					goto keepChecking;
				}
			}
			return true;
			keepChecking:;
		}
	}
	return false;
}

//Start at the top left corner of the array and check down diagnally
bool leftDiagWin(char** board, int numRows, int numCols, int numToWin){
	int row, col, n;
	for(row = 0; row <= numRows - numToWin; ++row){
		for(col = 0; col <= numCols - numToWin; ++col){
			char firstPiece = board[row][col];
			if(firstPiece == '*'){
				continue;
			}
			for(n = 1; n < numToWin; ++n){
				if(firstPiece != board[row + n][col + n]){
					goto keepChecking;
				}
			}	
			return true;
			keepChecking:;
		}
	}
	return false;
}

//Return if the game was a tie or not, meaning that there are no more spaces available but no one won
bool tied(char** board, int numRows, int numCols){
	int i, j;
	for (i = 0; i < numRows; ++i){
		for (j = 0; j < numCols; ++j){
			if(board[i][j] == '*'){
				return false;
			}
		}
	}
	return true;
}
