#include "sort.h"


/**
 * shell_sort - sort an array with shell sort
 * @array: given array
 * @size: size of the array
 *
 * Return: Nothing
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, in, out;
	int temp;

	if (!array || size <= 1)
		return;


	while (gap <= size / 3)
		gap = (gap * 3) - 1;

	while (gap > 0)
	{
		for (out = gap; out < size; out++)
		{
			temp = array[out];
			in = out;
			while (in > gap - 1 && array[in - gap] >= temp)
			{
				array[in] = array[in- gap];
				in = in - gap;
			}
			array[in] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
