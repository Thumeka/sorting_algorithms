#include "sort.h"

/**
 * shell_sort - array of integers to ascending order
 * @array: the array of integers
 * @size: size of integers
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, k, l;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (k = gap; k < size; k++)
		{
			l = k;
			while (l >= gap && array[l - gap] > array[l])
			{
				swap_q(array + l, array + (l - gap));
				l -= gap;
			}
		}
		print_array(array, size);
	}
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
