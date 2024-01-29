#include "processinput.h"
#include <stdbool.h>
#include <stdio.h>

int processinput(int table[3][3], bool its_player_turn)
{
	char move[3];
	move[2] = '\0';

	int row;
	int file;
	input(move, &row, &file);

	// printf("%d\t", row); printf("%d\n", file);
	if ((row >= 0 && row <= 2) && (file >= 0 && file <= 2)) {
		while (table[row][file] != -1) {
			input(move, &row, &file);
		}

		if (its_player_turn == true)
			table[row][file] = 0; // move from the engine it self
		else
			table[row][file] = 1; // move from the engine it self

		return 0;
	} else {
		return 1;
	}
}

void input(char c_input[3], int* row, int* file)
{
	printf("Your move: ");
	scanf("%s", c_input);
	*row = c_input[0] - 48;
	*file = c_input[1] - 48;
}
