#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in
 * ascending order using Bubble Sort
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
		return;
	i = 0;
	while (i < size - 1)
	{
		swapped = 0; /* Keeps track of whether we swapped anything */
		j = 0;
		while (j < size - i - 1)
		{
			/* If left number is bigger than right */
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
			j++;
		}
		if (swapped == 0)
			break;
		i++;
	}
}
