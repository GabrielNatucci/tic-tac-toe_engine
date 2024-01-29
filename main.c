#include "core/engine/engine.h"
#include "core/output/printtable.h"
#include "core/tictactoe/checkwinner.h"
#include "core/tictactoe/processinput.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printwinner(int table[3][3], int who)
{
	printtable(table);

	if (who == 2) {
		printf("Draw!!\n");
	} else if (who == 1) {
		printf("Player wins!!\n");
	} else {
		printf("Computer wins!!\n");
	}
}

int main(int argc, char* argv[])
{
	// log file
	FILE* f;
	f = fopen("engine.log", "w");

	if (f == NULL) {
		return -1;
	}

	// table thats used for the game itself
	// where -1 means that the square is clear
	// 0 means "x"
	// 1 means "o"
	int table[3][3] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 };

	// engine's string to play the moves
	char* engine_c = malloc(3 * sizeof(char));

	printf("WELCOME TO TIC TAC TOE VS ENGINE\n");
	printf("{0} if you want to start first\n");
	printf("{1} if you want the engien to start first\n:");

	int* temp = malloc(sizeof(int));
	do {
		scanf("%i", temp);
	} while (!(*temp == 0 || *temp == 1));

	bool does_player_starts_first = true;
	bool turn = true;
	// main game loop
	while (true) {
		if (turn == does_player_starts_first) { // if it's the player's turn
			printtable(table);

			bool valid = false; // checks if the input from the player is valid
			do {
				valid = processinput(table, does_player_starts_first);
			} while (valid);
		} else { // if it's the engine's turn
			engine(engine_c, table, does_player_starts_first, f); // function to call the engine
			int row = engine_c[0] - 48;
			int file = engine_c[1] - 48;

			if (does_player_starts_first == true) // move from the engine it self
				table[row][file] = 1;
			else
				table[row][file] = 0;
		}

		// checks if there is a winner
		int winner = checkwinner(table);

		if (winner != 0) {
			printwinner(table, winner);
			break;
		}

		if (turn == true)
			turn = false;
		else
			turn = true;
	}

	// free(engine_c);

	return 0;
}
