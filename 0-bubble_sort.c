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

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array of integers
 * @size: size of the array of integers
 * Returns: Void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int flag;


	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_int(array + j, array + j + 1);
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
