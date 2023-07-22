#include "sort.h"


/*
 * bubble_sort - sort an array using bubble sort
 * @array: given array
 * @size: size of the array
 *
 * Return: Nothing
*/
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int temp;
	bool swap = true;

	if (size <= 1)
		return;

	while (swap)
	{
		swap = false;
		
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = true;
			}
		}
		print_array(array, size);
		i++;
	}
}
