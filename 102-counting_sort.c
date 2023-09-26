#include "sort.h"

/**
 * counting_sort - counting the array to integers ascending order
 * @array: the array integer
 * @size: the size of the array
 */

void counting_sort(int *array, size_t size)
{
	int *add, *sort, max, k;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;

	max = maxi_get(array, size);
	add = malloc(sizeof(int) * (max + 1));
	if (add == NULL)
	{
		free(sort);
		return;
	}

	for (k = 0; k < (max + 1); k++)
		add[k] = 0;
	for (k = 0; k < (int)size; k++)
		add[array[k]] += 1;
	for (k = 0; k < (max + 1); k++)
		add[k] += add[k - 1];
	print_array(add, max + 1);

	for (k = 0; k < (int)size; k++)
	{
		sort[add[array[k]] - 1] = array[k];
		add[array[k]] -= 1;
	}

	for (k = 0; k < (int)size; k++)
		array[k] = sort[k];
	free(sort);
	free(add);
}

/**
 * maxi_get - get the maxi number
 * @array: the array of integer
 * @size: the size integer
 *
 * Return: integer
 */

int maxi_get(int *array, int size)
{
	int maxi, k;

	for (maxi = array[0], k = 1; k < size; k++)
	{
		if (array[k] > maxi)
			maxi = array[k];
	}

	return (maxi);
}
