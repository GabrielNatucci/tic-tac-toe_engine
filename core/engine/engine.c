#include "engine.h"
#include "../output/printtable.h"
#include <stdio.h>

int engine(char* c_input, int table[3][3])
{
	bool turn = true; // when true = engine's turn

	enginethink(c_input, table, turn);
	printf("%s\n", c_input);

	return 0;
}

int enginethink(char* c_input, int table[3][3], bool turn)
{
	int eval[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	char possibleMoves[9][3];

	int index = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (table[i][j] == -1) {
				possibleMoves[index][0] = i + 48;
				possibleMoves[index][1] = j + 48;
				possibleMoves[index][2] = '\0';
				index++;
			}
		}
	}

	for (int i = index; i < 9; i++) {
		possibleMoves[i][0] = '\0';
		possibleMoves[i][1] = '\0';
		possibleMoves[i][2] = '\0';
	}

	int best_eval = 1;
	// check winning continuation
	for (int i = 0; i < index; i++) {
		eval[i] = evaluate(table, turn, possibleMoves[i]);
		if (eval[i] < best_eval) {
			best_eval = eval[i];
		}
	}

	return best_eval;
}

int evaluate(int (*table)[3], bool turn, char* move)
{
	int local_table[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			local_table[i][j] = table[i][j];
		}
	}

	local_table[move[0] - 48][move[1] - 48] = 1;

	// // in case printing the local table is necessary
	printtable(local_table);

	char oponentPossibleMoves[9][3];

	int index = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (local_table[i][j] == -1) {
				oponentPossibleMoves[index][0] = i + 48;
				oponentPossibleMoves[index][1] = j + 48;
				oponentPossibleMoves[index][2] = '\0';
				index++;
			}
		}
	}

	for (int i = index; i < 9; i++) {
		oponentPossibleMoves[i][0] = '\0';
		oponentPossibleMoves[i][1] = '\0';
		oponentPossibleMoves[i][2] = '\0';
	}

	char c_move[3]; // current_move
	c_move[2] = '\0';
	for (int i = 0; i < index; i++) {
		c_move[0] = oponentPossibleMoves[i][0];
		c_move[1] = oponentPossibleMoves[i][1];
		local_table[c_move[0]][c_move[1]];
	}

	// printf("Eval: %d\n\n", eval);

	// return eval;
	return 0;
}
