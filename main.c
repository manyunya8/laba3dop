#include "laba3dop.h"
#include <stdio.h>
#define SIZE 3

int main()
{
	float arr[SIZE];
	float* a = arr;
	printf("Enter %d numbers greater than zero: \n", SIZE);
	for (int i = 0; i < SIZE; i++, a++)
	{
		if (scanf("%f", a) != 1)
			return printf("Not a number!\n");
		if (*a < 0)
			return printf("Negative number!\n");
		if (*a == 0)
			return printf("Zero!\n");
	}
	printf("The geometric mean:\n%.3f", geom(arr, SIZE));
	return 0;
}