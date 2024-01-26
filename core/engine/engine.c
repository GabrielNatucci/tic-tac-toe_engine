#include "engine.h"
#include "../output/printtable.h"
#include "../tictactoe/checkwinner.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int engine(char* c_input, int table[3][3])
{
	bool turn = true; // when true = engine's turn

	enginethink(c_input, table, turn);
	printf("%s\n", c_input);

	return 0;
}

int enginethink(char* c_input, int table[3][3], bool turn)
{
	srand(time(NULL)); // Initialization, should only be called once.

	int local_table[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			local_table[i][j] = table[i][j];
		}
	}

	// printtable(local_table);

	// int eval[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	char possibleMoves[9][3];

	int index = 0;
	int check;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (table[i][j] == -1) {
				possibleMoves[index][0] = i + 48;
				possibleMoves[index][1] = j + 48;
				possibleMoves[index][2] = '\0';

				local_table[i][j] = 1;

				check = checkwinner(local_table);
				printtable(local_table);
				printf("%d\n", check);

				if (check == -1) {
					c_input[0] = possibleMoves[index][0];
					c_input[1] = possibleMoves[index][1];
					c_input[2] = '\0';
					return 0;
				}
				local_table[i][j] = -1;
				index++;
			}
		}
	}

	int r = rand() % index; // Returns a pseudo-random integer between 0 and RAND_MAX.

	for (int i = index; i < 9; i++) {
		possibleMoves[i][0] = '\0';
		possibleMoves[i][1] = '\0';
		possibleMoves[i][2] = '\0';
	}

	c_input[0] = possibleMoves[r][0];
	c_input[1] = possibleMoves[r][1];
	c_input[2] = '\0';

	int best_eval = 0;

	return best_eval;
}

int evaluate(int (*table)[3], bool turn, char* move)
{
	// placer holder

	return 0;
}
