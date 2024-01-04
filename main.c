#include "core/engine/engine.h"
#include "core/output/printtable.h"
#include "core/tictactoe/checkwinner.h"
#include "core/tictactoe/processinput.h"
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int table[3][3] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 };

	bool game = true;
	bool winner;

	char engine[3];
	int i = 0;

	while (game && i < 15) {
		printtable(table);
		bool valid = false;
		do {
			valid = processinput(table);
		} while (valid);

		winner = checkwinner(table);

		enginethink(engine, table);


		// if (winner) {
		// 	printtable(table);
		// 	printf("WINNER!!!\n");
		// 	game = false;
		// }
		i++;
	}

	return 0;
}
