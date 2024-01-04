#include "engine.h"
#include "sorting/sorting.h"
#include <stdio.h>

int enginethink(char c_input[3], int table[3][3])
{
	int local_table[3][3];
	int l_table[3][3];
	char possibleMoves[9][3];
	bool turn = true; // when true = engine's turn

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

	// avalia a posicao
	int eval[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	for (int i = 0; i < 9; i++) {
		if (possibleMoves[i][0] != '\0') {
			eval[i] = evaluate(table, possibleMoves[i], turn);
			printf("%d\n", eval[i]);
		}
	}
	printf("\n");

	bubblesort(eval, 9);

	// for (int i = 0; i < 9; i++) {
	// 	printf("%d\n", eval[i]);
	// }

	c_input[0] = 'a';
	c_input[1] = 'b';

	return 0;
}

int evaluate(int table[3][3], char move[3], bool turn)
{
	int local_table[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			local_table[i][j] = table[i][j];
		}
	}

	int row = move[0] - 48;
	int file = move[1] - 48;
	local_table[row][file] = 0;

	// in case printing the local table is necessary
	// for (int i = 0; i < 3; i++) {
	// 	for (int j = 0; j < 3; j++) {
	// 		printf("%d", local_table[i][j]);
	// 	}
	// 	printf("\n");
	// }

	char p[2];
	if (turn == true) {
		p[0] = 'x';
	} else {
		p[0] = 'o';
	}
	p[1] = '\0';

	if (checkwinner(local_table, p)) {
		return 1;
	}

	return 0;
}
