#include "sort.h"

/**
 * insertion_sort_list - a doubly linked list with
 * insertion sort algorithm
 * @list: double pointer to head of linked list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *nextElement;

	if (list == NULL || (*list) == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		nextElement = current->next;
		while (current->prev != NULL && current->prev->n > current->n)
		{
			/* adjust for insert "current" at the correct position */
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->next->prev;
			current->next->prev = current;
			/* update pointer if the last is at the head of the list*/
			if (current->prev == NULL)
				(*list) = current;

			else
				current->prev->next = current;
			print_list(*list);
		}
		current = nextElement;
	}
}
