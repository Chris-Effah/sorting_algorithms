#include "sort.h"

/**
 * swap_nodes - swap two nodes in a doubly linked list
 * @list: list of integers
 * @node1: first node
 * @node2: second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
	node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;

	if (node1->prev)
		node1->prev->next = node2;
	else
		node2->prev = NULL;

	node1->prev = node2;
}

/**
 * insertion_sort_list - sorts a doubly linked
 * list of integers in ascending order
 * using the Insertion sort algorithm
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		insert = i->prev;
		while (insert != NULL && i->n < insert->n)
		{
			swap_nodes(list, insert, i);
			print_list(*list);
			insert = i->prev;
		}
	}
}
