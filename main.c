#include "core/engine/engine.h"
#include "core/output/printtable.h"
#include "core/tictactoe/checkwinner.h"
#include "core/tictactoe/processinput.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printwinner(int table[3][3], int who)
{
	printtable(table);

	if (who == 1)
		printf("Player wins!!\n");
	else
		printf("Computer wins!!\n");
}

int main(int argc, char* argv[])
{
	int table[3][3] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 };

	// bool game = true;
	int winner;

	char* engine_c = malloc(3 * sizeof(char));
	int i = 0;

	while (i < 15) {
		printtable(table);
		bool valid = false;
		do {
			valid = processinput(table);
		} while (valid);

		winner = checkwinner(table);

		if (winner != 0) {
			printwinner(table, winner);
			break;
		}

		engine(engine_c, table);
		int row = engine_c[0] - 48;
		int file = engine_c[1] - 48;
		table[row][file] = 1;
		
		winner = checkwinner(table);

		if (winner != 0) {
			printwinner(table, winner);
			break;
		}
		i++;
	}

	return 0;
}
