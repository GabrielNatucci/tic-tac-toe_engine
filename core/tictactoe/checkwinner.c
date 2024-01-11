#include "checkwinner.h"
#include <stdbool.h>

int checkwinner(int table[3][3])
{
	int row = checkrow(table);
	if (row == 1) {
		return 1;
	} else if (row == -1) {
		return -1;
	}

	int file = checkfile(table);
	if (file == 1) {
		return 1;
	} else if (file == -1) {
		return -1;
	}

	int diagonal = checkdiagonal(table);
	if (diagonal == 1) {
		return 1;
	} else if (diagonal == -1) {
		return -1;
	}

	return 0;
}

int checkrow(int table[3][3])
{
	bool x_winner;
	bool o_winner;

	for (int i = 0; i < 2; i++) {
		x_winner = (table[i][0] == 0 && table[i][1] == 0 && table[i][2] == 0);
		o_winner = (table[i][0] == 1 && table[i][1] == 1 && table[i][2] == 1);

		if (x_winner) {
			return 1;
		} else if (o_winner) {
			return -1;
		}
	}

	return 0;
}

int checkfile(int table[3][3])
{
	bool x_winner;
	bool o_winner;

	for (int j = 0; j < 2; j++) {
		x_winner = (table[0][j] == 0 && table[1][j] == 0 && table[2][j] == 0);
		o_winner = (table[0][j] == 1 && table[1][j] == 1 && table[2][j] == 1);

		if (x_winner) {
			return 1;
		} else if (o_winner) {
			return -1;
		}
	}

	return 0;
}

int checkdiagonal(int table[3][3])
{
	bool x_winner = (table[0][0] == 0 && table[1][1] == 0 && table[2][2] == 0);
	bool o_winner = (table[0][0] == 1 && table[1][1] == 1 && table[2][2] == 1);

	if (x_winner) {
		return 1;
	} else if (o_winner) {
		return -1;
	}

	x_winner = (table[2][0] == 0 && table[1][1] == 0 && table[0][2] == 0);
	o_winner = (table[2][0] == 1 && table[1][1] == 1 && table[0][2] == 1);

	if (x_winner) {
		return 1;
	} else if (o_winner) {
		return -1;
	}

	return 0;
}
