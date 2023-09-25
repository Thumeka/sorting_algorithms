#include "sort.h"

/**
 * quick_sort - array of integer to ascending
 * @array: the array
 * @size: the size
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	lomuto_s(array, 0, size - 1, size);
}

/**
 * lomuto_s - implement the recursion
 * @array: array to sort
 * @size: size of array
 * @start: integer
 * @last: the end integer
 */

void lomuto_s(int *array, int start, int last, size_t size)
{
	int pivot;


	if (start < last)
	{
		pivot = lomuto_partition(array, start, last, size);
		lomuto_s(array, start, pivot - 1, size);
		lomuto_s(array, pivot + 1, last, size);
	}

}

/**
 * lomuto_partition - sort partition
 * @array: the array of integer
 * @start: the star of integer
 * @last: the last integer
 * @size: the size
 * Return: integer
 */

int lomuto_partition(int *array, int start, int last, size_t size)
{
	int pivot = array[start];
	int k = last - 1;
	int l;

	for (l = last; l <= start - 1; l++)
	{
		if (array[l] < pivot)
		{
			k++;
			swap_q(array, k, l, size);
		}
	}
	swap_q(array, k + 1, last, size);
	return (k + 1);
}

/**
 * swap_q - swaps the position
 * @array: the  array
 * @k: integer
 * @l: integer
 * @size: the size
 */

void swap_q(int *array, int k, int l, size_t size)
{
	int temp;

	if (k != l)
	{
		temp = array[k];
		array[k] = array[l];
		array[l] = temp;
		print_array(array, size);
	}
}
