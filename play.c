#include "play.h"
#include "endconditions.h"
#include "board.h"

//This is the main function to actually play the game
void playGame(int numRows, int numCols, int numToWin){
	char** board = createBoard(numRows, numCols);
	int turn = 0;
	//While the game is not over, keep playing
	while(!gameOver(board, numRows, numCols, numToWin)){
		//Print the board every time
		printBoard(board, numRows, numCols);
		//This label is to move again if the column the user requested is full
		int move; 
		moveAgain: move = getValidPlay(numCols);
		int i = 0;
		char token;
		//Different character depending on whose turn it is (X for player 1, O for player 2)
		if (turn == 0){
			token = 'X';
		} else {
			token = 'O';
		}
		//Determine which row to put the piece in depending on the first empty space
		for(i = numRows - 1; i >= 0; --i){
			//If row is full get a new move
			if(board[0][move] != '*'){
				goto moveAgain;	
			}
			//Place the piece down and exit the loop
			if(board[i][move] == '*'){				
				board[i][move] = token;
				break;
			}	
		}
		//If the game is not over at this point change turns and continue
		if(!gameOver(board, numRows, numCols, numToWin)){
			turn = (turn + 1) % 2;		
		}
	}
	//When the game is over, print the board one last time, output the results of the game, and destroy the board
	printBoard(board, numRows, numCols);
	output(turn, gameWon(board, numRows, numCols, numToWin));
	destroyBoard(board, numRows);
}

//Output the results when the game is over
void output(int player, bool won){
	//If someone one print out which player one
	if (won){
		printf("Player %d Won!\n", player + 1);
	} else {
		//Otherwise the game was a tie
		printf("Tie game!\n");
	}
}

//Get a valid integer from the user between 0 and the number of columns - 1
int getValidPlay(int numCols){
	int play, numArgsRead;
	//Keep printing the message and asking for input until it is valid
	do{
		printf("Enter a column between 0 and %d to play in: ", numCols - 1);
		numArgsRead = scanf("%d", &play);
	}while(!validFormat(numArgsRead, play, numCols));
	return play;
}

//Ensure the user input is valid
bool validFormat(int numArgsRead, int play, int numCols){
	char newLine = '\n';
	if(numArgsRead != 1){
		return false;
	}
	do{
		//Make sure there is only white space after the user inputs
		scanf("%c", &newLine); 
		if(!isspace(newLine)){ 
			return false;
		}
	}while(newLine != '\n'); 
	//Make sure the user inputted value is within the correct index
	if (play < 0 || play > numCols - 1){
		return false;
	}
	return true;
}
