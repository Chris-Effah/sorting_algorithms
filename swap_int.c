#include "sort.h"
/**
 * swap_int - a function that swaps integers
 * @i: pointer to first integer
 * @j: pointer to second integer
 * Return: Void
 */
void swap_int(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}
