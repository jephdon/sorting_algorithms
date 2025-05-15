#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order using Insertion Sort
 * @list: Pointer to the head of the list
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	/* Start with the second node */
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current->next;
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			/* Update the pointers to swap node */
			if (prev->prev != NULL)
				prev->prev->next = current;
			else
		/* Update head if swapping with the first node */
				*list = current;
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;
			current->prev = prev->prev;
			current->next = prev;
			prev->prev = current;
			/* Move prev back one step */
			prev = current->prev;
			print_list(*list);
		}
		/* Move to the next unsorted node */
		current = temp;
	}
}
