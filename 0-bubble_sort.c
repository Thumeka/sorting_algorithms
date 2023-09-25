#include "sort.h"

/**
 * bubble_sort - sorts them to ascending order
 * @array: integer
 * @size: size
 */

void bubble_sort(int *array, size_t size)
{
	size_t k, l, asc;

	for (k = 0; k < size; k++)
	{
		for (l = 0; l < size - 1; l++)
		{
			if (array[l] > array[l + 1])
			{
				asc = array[l];
				array[l] = array[l + 1];
				array[l + 1] = asc;
				print_array(array, size);
			}
		}
	}
}
