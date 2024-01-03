#include "printtable.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int table[3][3] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};

  printtable(table);
  return 0;
}
