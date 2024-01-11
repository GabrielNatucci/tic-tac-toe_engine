#include "../tictactoe/checkwinner.h"
#include <stdbool.h>

int engine(char* c_input, int table[3][3]);
int enginethink(char* c_input, int table[3][3], bool turn);
int evaluate(int (*table)[3], bool turn, char* move);
int checkOpponentsResponse();
