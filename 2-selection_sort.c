#include "sort.h"

/**
 * selection_sort - integer into ascending order
 * @array: arrays
 * @size: the sizes
 */

void selection_sort(int *array, size_t size)
{
	size_t k, l, asc;

	for (k = 0; k < size - 1; k++)
	{
		asc = k;
		for (l = k + 1; l < size; l++)
		{
			if (array[asc] > array[l])
				asc = l;
		}
		if (asc != k)
		{
			swapped(&array[k], &array[asc]);
			print_array(array, size);
		}
	}
}

/**
 * swapped - swap the numberes or positions
 * @asc1: integer
 * @asc2: integer
 */

void swapped(int *asc1, int *asc2)
{
	int posi;

	posi = *asc1;
	*asc1 = *asc2;
	*asc2 = posi;
}
