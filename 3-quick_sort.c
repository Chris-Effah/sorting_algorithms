#include "sort.h"

/**
  * swap_int - Swaps two integers i an array
  * @i: Pointer to first integer to swap
  * @j: Pointer second integer to swap
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
  * lomuto_partition - Rearrange elements in an array according
  * to the lomuto_partition scheme
  * @array: The array of integers
  * @size: The size of the array
  * @left: The starting index of the subset to rearrange
  * @right: The ending index of the subset to rearrange
  * Return: the final partition index
  */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int pivot, high, low;

	*pivot = array + right;
	for (high = low = left; low < right; low++)
	{
		if (array[low] < *pivot)
		{
			if (high < low)
			{
				swap_int(array + low, array + high);
				print_array(array, size);
			}
			high++;
		}
	}
	
	if (array[high] > *pivot)
	{
		swap_int(array + high, pivot);
		print_array(array, size);
	}
	return (high);
}

/**
  * lomuto_sort - Implement the quicksort algorithm
  * @array: An array of integers
  * @size: The size of the array
  * @left: The starting index of the array to partition
  * @right: the ending index of the array to partition
  * Description: Uses the Lomuto partition scheme
  */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}


/**
  * quick_sort - Sorts an array of integers in ascending order
  * using the quicksort algorithm
  * @array: An array of integers
  * @size: The size of the array
  * Description: Use the Lomuto partition scheme to print the 
  * array after swapping two elements
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	
	lomuto_sort(array, size, 0, size - 1);
}
