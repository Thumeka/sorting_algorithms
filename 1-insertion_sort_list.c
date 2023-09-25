#include "sort.h"

/**
 * insertion_sort_list - sorts the double linked list to ascending order
 * @list: structure
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head;

	if (!list || !*list)
		return;

	head = *list;

	while (head && head->next)
	{
		if (head->n > head->next->n)
		{
			swap_nodes(&head, list);
			print_list(*list);

			while (head && head->prev)
			{
				if (head->n < (head->prev)->n)
				{
					head = head->prev;
					swap_nodes(&head, list);
					print_list(*list);
					head = head->next;
				}
				head = head->prev;
			}
		}
		head = head->next;
	}
}
