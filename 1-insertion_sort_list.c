#include "sort.h"


/**
 *
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *temp, *temp2;

	if (!list || !current)
		return;

	current = current->next->next;


	while (1)
	{
		temp = current->prev;
		while (temp->prev && temp->n > temp->prev->n)
		{
			temp2 = temp->prev;
			temp2->next = temp->next;
			temp->prev = temp2->prev;
			temp2->prev = temp;
			temp->next = temp2;
			print_list(*list);
		}
		if (!current)
			break;

		current = current->next;
	}
}

/**
 *
*/
void insertion_sort_array(int array[], size_t size)
{
	size_t i;
	int current, j;

	for (i = 1; i < size; i++)
	{
		current = array[i];
		j = i - 1;
		for (; j >= 0 && array[j] > current; j--)
		{
			array[j + 1] = array[j];
			print_array(array, size);
		}
		array[j + 1] = current;
	}
}
