#include "sort.h"

/**
 * swap_nodes - A program that swaps two nodes in a listint_t doubly-link list
 * @h: A ptr to the head of the doubly-linked list.
 * @n1: A ptr to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - A prog that sorts a doubly linked list of ints
 *                       using the insertion sort algorithm.
 * @list: A ptr to the head of a doubly-linked list of ints.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insert, *p;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = p)
	{
		p = i->next;
		insert = i->prev;

		while (insert != NULL && i->n < insert->n)
		{
			swap_nodes(list, &insert, i);
			print_list((const listint_t *)*list);
		}
	}
}
