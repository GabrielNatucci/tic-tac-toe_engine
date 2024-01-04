#include "checkwinner.h"

int checkwinner(int table[3][3], char* p)
{
	int coe;
	if (p[0] == 'x') {
		coe = 0;
	} else if (p[0] == 'o') {
		coe = 1;
	}

	// for checking rows
	for (int i = 0; i < 2; i++) {
		if (checkrow(table, i, coe)) {
			return 1;
		}
	}

	for (int j = 0; j < 2; j++) {
		if (checkfile(table, j, coe)) {
			return 1;
		}
	}

	if (checkdiagonal(table, coe)) {
		return 1;
	}

	return 0;
}

int checkrow(int table[3][3], int row, int c)
{
	if (table[row][0] == c && table[row][1] == c && table[row][2] == c) {
		return 1;
	} else {
		return 0;
	}
}

int checkfile(int table[3][3], int file, int c)
{
	if (table[0][file] == c && table[1][file] == c && table[2][file] == c) {
		return 1;
	} else {
		return 0;
	}
}

int checkdiagonal(int table[3][3], int c)
{
	if (table[0][0] == c && table[1][1] == c && table[2][2] == c) {
		return 1;
	}

	if (table[2][0] == c && table[1][1] == c && table[0][2] == c) {
		return 1;
	}

	return 0;
}
