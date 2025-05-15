#include "sort.h"

/**
 * swap - Swaps two integers in an array and prints the array
 * @array: The array containing the integers
 * @a: Index of the first integer
 * @b: Index of the second integer
 * @size: Size of the array
 */
void swap(int *array, size_t a, size_t b, size_t size)
{
	int temp;

	if (a != b) /* Only swap if indices are different */
	{
		temp = array[a];
		array[a] = array[b];
		array[b] = temp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme
 * @array: The array to partition
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: The final position of the pivot
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high]; /* Pivot is the last element */
	size_t i = low; /* Where the smallest element goes */
	size_t j = low;

	while (j < high)
	{
		if (array[j] <= pivot)
		{
			swap(array, i, j, size); /* Move element left */
			i++;
		}
		j++;
	}
	swap(array, i, high, size);
	return (i);
}
/**
 * quicksort_recursive - Recursively sorts the array using Quick Sort
 * @array: The array to sort
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quicksort_recursive(int *array, size_t low, size_t high, size_t size)
{
	size_t pi;

	if (low < high) /* If there's more than one element */
	{
		pi = lomuto_partition(array, low, high, size);
		if (pi > high) /* Sort left side */
			quicksort_recursive(array, low, pi - 1, size);
		if (pi < high) /* Sort right side */
			quicksort_recursive(array, pi + 1, high, size);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_recursive(array, 0, size - 1, size);
}
