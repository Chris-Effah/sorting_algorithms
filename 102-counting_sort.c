#include "sort.h"

/**
 * counting_sort -  a function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: array of integers
 * @size: size of array
 **/
void counting_sort(int *array, size_t size)
{
	int max_val;
	int *count_array, i, *output_array, output_index;

	if (size <= 1)
	{
		return;
	}

	max_val = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max_val)
		{
			max_val = array[i];
		}

	}
	count_array = calloc(max_val + 1, sizeof(int));

	for (i = 0; i < (int)size; i++)
	{
		count_array[array[i]]++;
	}
	output_array = malloc(size * sizeof(int));

	output_index = 0;
	for (i = 0; i <= max_val; i++)
	{
		while (count_array[i] > 0)
		{
			output_array[output_index] = i;
			output_index++;
			count_array[i]--;
		}

	}
	for (i = 0; i < (int)size; i++)
		array[i] = output_array[i];
	free(count_array);
	free(output_array);
}
