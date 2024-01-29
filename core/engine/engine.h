#include "../tictactoe/checkwinner.h"
#include <stdbool.h>
#include <stdio.h>

int engine(char* c_input, int table[3][3], FILE* f);
int enginethink(char* c_input, int table[3][3], bool turn, FILE* f);
int evaluate(int (*table)[3], bool turn, char* move, FILE* f);
