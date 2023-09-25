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

/**
 * swap_nodes - changes the position of the numbers
 * @head: the head
 * @list: structure
 */

void swap_nodes(listint_t **head, listint_t **list)
{
	listint_t *node = *head;
	listint_t *nod1, *nod2;

	if (!(*head)->prev)
		*list = (*head)->next;

	nod1 = node->next;
	node->next = nod1->next;
	nod2 = node->prev;
	node->prev = nod1;
	nod1->next = node;
	nod1->prev = nod2;

        if (nod1->prev)
		nod1->prev->next = nod1;
	if (node->next)
		node->next->prev = node;
	*head = nod1;
}
