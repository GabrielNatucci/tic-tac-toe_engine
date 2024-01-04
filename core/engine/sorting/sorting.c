#include "sorting.h"
#include <stdbool.h>
// #include <stdio.h>

void bubblesort(int arry[], int n)
{
	bool swapped;
	int tmp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arry[j] < arry[j + 1]) {
				tmp = arry[j];
				arry[j] = arry[j + 1];
				arry[j + 1] = tmp;
			}
		}
	}
}
