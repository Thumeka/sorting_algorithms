#include "sort.h"

/**
 * swap_nodes - changes the position of the numbers
 * @head: the head
 * @list: structure
 */

void swap_nodes(listint_t **head, listint_t **list)
{
	listint_t *node = *head;
	listint *nod1, nod2;

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
