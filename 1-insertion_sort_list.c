#include "sort.h"


/**
 *insert_swap - swap between 2 nodes
 * @head: head of the list
 * @cur: current node
 * @prev: prevois node
 *
 * Return: Nothing
*/
void insert_swap(listint_t **head, listint_t **cur, listint_t *prev)
{
	(*cur)->next = prev->next;
	if (prev->next)
		prev->next->prev = *cur;

	prev->prev = (*cur)->prev;
	prev->next = *cur;
	if ((*cur)->prev)
		(*cur)->prev->next = prev;
	else
		*head = prev;
	(*cur)->prev = prev;
	*cur = prev->prev;
}
/**
 * insertion_sort_list - sort an list using insertion sort
 * @list: given list
 *
 * Return: Nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *it, *ins, *temp;

	for (it = (*list)->next; it; it = temp)
	{
		temp = it->next;
		ins = it->prev;

		while (ins && it->n < ins->n)
		{
			insert_swap(list, &ins, it);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * insertion_sort_array - sort an array using insertion sort
 * @array: given array
 * @size: size of the array
 *
 * Return: Nothing
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
