#include "engine.h"
#include "../output/printtable.h"
#include "../tictactoe/checkwinner.h"
#include <stdbool.h>
#include <stdio.h>

int engine(char* c_input, int table[3][3], FILE* f)
{
	bool turn = true; // when true = engine's turn

	enginethink(c_input, table, turn, f);

	return 0;
}

int enginethink(char* c_input, int table[3][3], bool turn, FILE* f)
{
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

	int eval[index];

	for (int i = 0; i < index; i++) {
		fprintf(f, "Para o lance %s:\n", possibleMoves[i]);
		eval[i] = evaluate(table, turn, possibleMoves[i], f);
	}

	int iBest = 0;
	int bestEval = 99999999;

	for (int i = 0; i < index; i++) {
		if (eval[i] < bestEval) {
			bestEval = eval[i];
			iBest = i;
		}
	}

	for (int i = index; i < 9; i++) {
		possibleMoves[i][0] = '\0';
		possibleMoves[i][1] = '\0';
		possibleMoves[i][2] = '\0';
	}

	c_input[0] = possibleMoves[iBest][0];
	c_input[1] = possibleMoves[iBest][1];
	c_input[2] = '\0';

	return bestEval;
}

int evaluate(int (*table)[3], bool turn, char* move, FILE* f)
{

	int local_table[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			local_table[i][j] = table[i][j];
		}
	}

	if (turn == true)
		local_table[move[0] - 48][move[1] - 48] = 1;
	else
		local_table[move[0] - 48][move[1] - 48] = 0;

	// logs the current table
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (table[i][j] == -1) {
				fprintf(f, ". ");
			} else if (table[i][j] == 0) {
				fprintf(f, "x ");
			} else if (table[i][j] == 1) {
				fprintf(f, "o ");
			}
		}
		fprintf(f, "\n");
	}
	fprintf(f, "\n");

	if (checkwinner(local_table) == -1) {
		fprintf(f, "Eval: %d\n\n", -1);
		return -1;
	} else if (checkwinner(local_table) == 1) {
		fprintf(f, "Eval: %d\n\n", 1);
		return 1;
	} else if (checkwinner(local_table) == 2) {
		fprintf(f, "Eval: %d\n\n", 2);
		return 0;
	}

	if (turn == true)
		turn = false;
	else
		turn = true;

	char possibleMoves[9][3];
	long signed int index = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (local_table[i][j] == -1) {
				possibleMoves[index][0] = i + 48;
				possibleMoves[index][1] = j + 48;
				possibleMoves[index][2] = '\0';
				index++;
			}
		}
	}

	int eval;
	int maxEval = 1;

	if (turn) {
		maxEval = 99999999;
		for (int i = 0; i < index; i++) {
			eval = evaluate(local_table, turn, possibleMoves[i], f);
			if (eval < maxEval) {
				maxEval = eval;
			}
		}
		return maxEval;
	} else {
		maxEval = -99999999;
		for (int i = 0; i < index; i++) {
			eval = evaluate(local_table, turn, possibleMoves[i], f);
			if (eval > maxEval) {
				maxEval = eval;
			}
		}
		return maxEval;
	}

	return 0;
}
