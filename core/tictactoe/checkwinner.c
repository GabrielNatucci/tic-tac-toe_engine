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

	return 0;
}

int checkrow(int table[3][3])
{
	// printf("row:\n");

	for (int i = 0; i < 2; i++) {
		bool x_winner = (table[i][0] == 0 && table[i][1] == 0 && table[i][2] == 0);
		bool o_winner = (table[i][0] == 1 && table[i][1] == 1 && table[i][2] == 1);
		// printf("\nx: %d\t", x_winner);
		// printf("o: %d\n", x_winner);

		if (x_winner) {
			return 1;
		} else if (o_winner) {
			return -1;
		}
	}

	return 0;
}

int checkcolumn(int table[3][3])
{
	bool x_winner;
	bool o_winner;

	// printf("file:\n");

	for (int j = 0; j < 2; j++) {
		bool x_winner = (table[0][j] == 0 && table[1][j] == 0 && table[2][j] == 0);
		bool o_winner = (table[0][j] == 1 && table[1][j] == 1 && table[2][j] == 1);
		// printf("\nx: %d\t", x_winner);
		// printf("o: %d\n", x_winner);

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

	// printf("diagonal:\n");
	// printf("\nx: %d\t", x_winner);
	// printf("o: %d\n", x_winner);

	if (x_winner) {
		return 1;
	} else if (o_winner) {
		return -1;
	}

	x_winner = (table[2][0] == 0 && table[1][1] == 0 && table[0][2] == 0);
	o_winner = (table[2][0] == 1 && table[1][1] == 1 && table[0][2] == 1);
	// printf("\nx: %d\t", x_winner);
	// printf("o: %d\n", x_winner);

	if (x_winner) {
		return 1;
	} else if (o_winner) {
		return -1;
	}

	return 0;
}
