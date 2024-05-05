#include "sort.h"

/**
 * swap - swap between two nodes
 * @i: node addy
 * @j: node addy
 */

void swap(listint_t *i, listint_t *j)
{
	if (i->prev)
		i->prev->next = j;
	if (j->next)
		j->next->prev = i;
	i->next = j->next;
	j->prev = i->prev;
	i->prev = j;
	j->next = i;
}

/**
 * inserttion_sort_list - insertion sort algorithm
 * list: list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *x, *y;

	if (!list || !*list || !(*list)->next)
		return;
	x = (*list)->next;

	while (x)
	{
		y  = x;
		x = x->next;

		while (y && y->prev)
		{
			if (y->prev->n > y->n)
			{
				swap(y->prev, y);
				if (!y->prev)
					*list = y;
				print_list((const listint_t *)*list);
			}
			else
				y = y->prev;
		}

	}
}
