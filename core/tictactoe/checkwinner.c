#include "checkwinner.h"
#include "../output/printtable.h"
#include <stdbool.h>

int checkwinner(int table[3][3])
{
	// printtable(table);

	int row = checkrow(table);
	if (row != 0) {
		return row;
	}

	int file = checkcolumn(table);
	if (file != 0) {
		return file;
	}

	int diagonal = checkdiagonal(table);
	if (diagonal != 0) {
		return diagonal;
	}

	int draw = 2;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (table[i][j] == -1) {
				draw = 0;
			}
		}
	}

	return draw;
}

int checkrow(int table[3][3])
{
	for (int i = 0; i < 3; i++) {
		if ((table[i][0] == 0 && table[i][1] == 0 && table[i][2] == 0)) {
			return 1;
		}

		if ((table[i][0] == 1 && table[i][1] == 1 && table[i][2] == 1)) {
			return -1;
		}
	}

	return 0;
}

int checkcolumn(int table[3][3])
{
	for (int j = 0; j < 3; j++) {
		if ((table[0][j] == 0 && table[1][j] == 0 && table[2][j] == 0)) {
			return 1;
		}

		if ((table[0][j] == 1 && table[1][j] == 1 && table[2][j] == 1)) {
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
