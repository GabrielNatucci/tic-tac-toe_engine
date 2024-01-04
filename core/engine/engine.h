#include "../tictactoe/checkwinner.h"
#include <stdbool.h>

int enginethink(char c_input[3], int table[3][3]);
int evaluate(int table[3][3], char move[3], bool turn);
