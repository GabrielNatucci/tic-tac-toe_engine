#include "printtable.h"
#include <stdio.h>

void printtable(int table[3][3])
{
	printf("\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (table[i][j] == -1) {
				printf(". ");
			} else if (table[i][j] == 0) {
				printf("x ");
			} else if (table[i][j] == 1) {
				printf("o ");
			}
		}
		printf("\n");
	}
}
