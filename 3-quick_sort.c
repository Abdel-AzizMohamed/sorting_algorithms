#include "sort.h"


/**
 * swap - swap bettwen 2 numbers in array
 * @x: first number
 * @y: second number
 *
 * Return: Nothing
*/
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * quicksort_recursion - loop through each partition to sort
 * @array: the given array
 * @low: this first value of the partition
 * @high: the last value of the partition(pivot)
 * @size: size of the array
 *
 * Return: Nothing
*/
void quicksort_recursion(int array[], int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);

		quicksort_recursion(array, low, pivot_index - 1, size);
		quicksort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * partition - creates a new partition and sort it
 * @array: given array
 * @low: this first value of the partition
 * @high: the last value of the partition(pivot)
 * @size: size of the array
 *
 * Return: new index of the pivot
*/
int partition(int array[], int low, int high, size_t size)
{
	int pivot_value = array[high], i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}

	swap(&array[i], &array[high]);
	print_array(array, size);

	return (i);
}

/**
 * quick_sort - sort an array with quick sort
 * @array: given array
 * @size: size of the array
 *
 * Return: Nothing
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	quicksort_recursion(array, 0, size - 1, size);
}
