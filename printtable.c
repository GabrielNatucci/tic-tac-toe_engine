#include <stdio.h>

void printtable(int table[3][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == -1) {
				printf("%d", table[i][j]);
			}
		}
		printf("\n");
	}
}
