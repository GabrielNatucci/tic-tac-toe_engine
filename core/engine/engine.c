#include "engine.h"
#include "../tictactoe/checkwinner.h"
#include <stdbool.h>
#include <stdio.h>
// #include <stdlib.h>

void enginethink(char c_input[3], int table[3][3])
{
	int local_table[3][3];
	int l_table[3][3];
	char moves[9][3];

	int index = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (table[i][j] == -1) {
				moves[index][0] = i + 48;
				moves[index][1] = j + 48;
				moves[index][2] = '\0';
				index++;
			}
		}
	}

	for (int i = index; i < 9; i++) {
		moves[i][0] = '\0';
		moves[i][1] = '\0';
		moves[i][2] = '\0';
	}

	for (int i = 0; i < 9; i++) {
		printf("%s\n", moves[i]);
	}

	// bool move = false;
	//
	// while (!move) {
	// 	evaluate(l_table);
	// }

	c_input[0] = 'a';
	c_input[1] = 'b';
}

int evaluate(int table[3][3])
{
	if (checkwinner(table)) {
		return 1;
	}

	return 0;
}
