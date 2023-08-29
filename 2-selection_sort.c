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
 * selection_sort - a function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: Void
 **/
void selection_sort(int *array, size_t size)
{
	size_t min_index, a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		min_index = a;

		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[min_index])
			{
				min_index = b;
			}
		}
		if (min_index != a)
		{
			swap_int(&array[a], &array[min_index]);
			print_array(array, size);
		}
	}


}
