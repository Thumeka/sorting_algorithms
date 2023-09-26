#include "sort.h"

/**
 * heap_sort - array of integers in ascending order
 * @array: the arrays integer
 * @size: the size of integer
 */

void heap_sort(int *array, size_t size)
{
	int k;

	if (array == NULL || size < 2)
		return;

	for (k = (size / 2) - 1; k >= 0; k--)
		sift_down(array, size, size, k);

	for (k = size - 1; k > 0; k--)
	{
		swap_q(array, array + k);
		print_array(array, size);
		sift_down(array, size, k, 0);
	}
}

/**
 * sift_down - implement the sift down
 * @array: the binary
 * @size: the size of the array
 * @root: root node
 * @base: the row of tree arrays
 */

void sift_down(int *array, size_t size, size_t root, size_t base)
{
	size_t below, above, under;

	below = 2 * root + 1;
	above = 2 * root + 2;
	under = root;

	if (below < base && array[below] > array[under])
		under = below;
	if (above < base && array[above] > array[under])
		under = above;

	if (under != root)
	{
		swap_q(array + root, array + under);
		print_array(array, size);
		sift_down(array, size, base, under);
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
