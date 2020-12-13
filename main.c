#include "laba3dop.h"
#define SIZE 2

int main()
{
	float arr[SIZE];
	if (inArr(arr, SIZE) == 1)
		return printf("Not a number!\n");
	float res = geom(arr, SIZE);
	if (res == -1)
		return printf("Only natural numbers!\n");
	printf("The geometric mean:\n%.3f", res);
	return 0;
}