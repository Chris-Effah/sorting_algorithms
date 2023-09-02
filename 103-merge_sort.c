#include "sort.h"

/**
 * merge - Merge two sub arrays
 * @array: array to be merged
 * @left: left sub array
 * @right: the right sub array
 * @size_left: size of the left sub-array
 * @size_right: size of the right sub-array
 **/
void merge(int *array, int *left, int *right,
		size_t size_left, size_t size_right)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc((size_left + size_right) * sizeof(int));

	if (temp == NULL)
	{
		free(array);
		return;
	}
	printf("Merging...\n[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);
	while (i < size_left && j < size_right)
	{
		if (left[i] <= right[j])
		{
			temp[k] = left[i];
			i++;
		}
		else
		{
			temp[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < size_left)
	{
		temp[k++] = left[i++];
	}
	while (j < size_right)
	{
		temp[k++] = right[j++];
	}
	for (k = 0; k < size_left + size_right; k++)
		array[k] = temp[k];
	printf("[Done]: ");
	print_array(array, size_left + size_right);
	free(temp);
}
/**
 * merge_sort - function to sort an array using the merge sorting algorithm
 * @array: array to be sorted
 * @size: size of array
 **/
void merge_sort(int *array, size_t size)
{
	int *left, *right;
	size_t size_left, mid, size_right;

	if (array == NULL || size < 2)
		return;

	mid = size / 2;
	size_left = mid;
	size_right = size - mid;
	left = array;
	right = array + mid;
	if (size > 1)
	{

		merge_sort(left, size_left);
		merge_sort(right, size_right);
		merge(array, left, right, size_left, size_right);
	}
}
