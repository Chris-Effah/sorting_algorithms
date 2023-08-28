#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: double pointer to the head of the list
 * @node1: first node
 * @node2: second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
	}
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node2->next = node1;
	node1->prev = node2;
}


/**
 * insertion_sort_list - a function that sorts a doubly linked
 * list of integers in ascending order using the Insertion sort algorithm
 * @list: list of intergers to be sorted
 * Return: Void
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *insertion_point;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insertion_point = current->prev;
		temp = current;

		while (insertion_point != NULL && insertion_point->n > temp->n)
		{
			swap_nodes(list, insertion_point, temp);
			insertion_point = temp->prev;
			print_list(*list);

			temp = insertion_point;

		}
		current = current->next;
	}
}
