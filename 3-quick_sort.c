#include "sort.h"

/**
 * quick_sort - array of integer to ascending
 * @array: the array
 * @size: the size
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
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


	if (start - last > 0)
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
	int *quick, left, right;


	quick = array + last;
	for (left = right = start; right < last; right++)
	{
		if (array[right] < *quick)
		{
			if (left < right)
			{
				swap_q(array + right, array + left);
				print_array(array, size);
			}
			left++;
		}
	}

	if (array[left] > *quick)
	{
		swap_q(array + left, quick);
		print_array(array, size);
	}
	return (left);
}

/**
 * swap_q - swaps the position
 * @sw1: position first
 * @sw2: second position
 */

void swap_q(int *sw1, int *sw2)
{
	int swop;

	swop = *sw1;
	*sw1 = *sw2;
	*sw2 = swop;
}
