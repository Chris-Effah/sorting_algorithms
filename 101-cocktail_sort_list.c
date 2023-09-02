#include "sort.h"

/**
 * swap_nodes - Swaps a node in a listint_t doubly-linked list
 * of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list
 * @node1: A pointer to the tail of the doubly-linked list.
 * @node2: A pointer to the current swapping node of the cocktail shaker
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (node1->prev == NULL)
		*list = node1;
	if (node2->next == NULL)
		*list = node2;
}

/**
 * cocktail_sort_list - Sorts a listint_t doubly-linked list of integers
 * @list: A pointer to the head of the listint_t doubly-linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *p1, *p2, *end = NULL;

	if (list == NULL || *list == NULL)
		return;
	do {
		swapped = 0;
		p1 = *list;
		while (p1->next != end)
		{
			if (p1->n > p1->next->n)
			{
				swap_nodes(list, p1, p1->next);
				print_list(*list);
				swapped = 1;
			}
			else
				p1 = p1->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		p2 = p1;
		while (p2->prev != *list)
		{
			if (p2->n < p2->prev->n)
			{
				swap_nodes(list, p2->prev, p2);
				print_list(*list);
				swapped = 1;
			}
			else
				p2 = p2->prev;
		}
		end = p2;
	} while (swapped);
}
