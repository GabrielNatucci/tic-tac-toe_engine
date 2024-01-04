#include "checkwinner.h"

int checkwinner(int table[3][3])
{
	// for checking rows
	for (int i = 0; i < 2; i++) {
		if (checkrow(table, i)) {
			return 1;
		}
	}

	for (int j = 0; j < 2; j++) {
		if (checkfile(table, j)) {
			return 1;
		}
	}

	if (checkdiagonal(table)) {
		return 1;
	}

	return 0;
}

int checkrow(int table[3][3], int row)
{
	if (table[row][0] == 0 && table[row][1] == 0 && table[row][2] == 0) {
		return 1;
	} else {
		return 0;
	}
}

int checkfile(int table[3][3], int file)
{
	if (table[0][file] == 0 && table[1][file] == 0 && table[2][file] == 0) {
		return 1;
	} else {
		return 0;
	}
}

int checkdiagonal(int table[3][3])
{
	if (table[0][0] == 0 && table[1][1] == 0 && table[2][2] == 0) {
		return 1;
	}

	if (table[2][0] == 0 && table[1][1] == 0 && table[0][2] == 0) {
		return 1;
	}

	return 0;
}
