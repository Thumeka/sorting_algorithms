#ifndef SORT_H
#define SORT_H

/* LIBRARIES */

#include <stdio.h>
#include <stdlib.h>

/* STRUCTURES */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swapped(int *asc1, int *asc2);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap_q(int *sw1, int *sw2);
void shell_sort(int *array, size_t size);
void sift_down(int *array, size_t size, size_t root, size_t base);
void heap_sort(int *array, size_t size);
int maxi_get(int *array, int size);
void counting_sort(int *array, size_t size);
int lomuto_partition(int *array, int start, int last, size_t size);
void lomuto_s(int *array, int start, int last, size_t size);
void swap_nodes(listint_t **head, listint_t **list);

#endif
