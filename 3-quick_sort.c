#include "sort.h"
/**
 * swap - swaps the values of two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partitions an array into two segments based on a pivot
 * @array: array to be partitioned
 * @size: size of the array
 * Return: index of the pivot after partitioning
 */
size_t partition(int *array, size_t size)
{
	int pivot = array[size - 1];
	size_t partition_index = 0, i = 0;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] < pivot)
		{
			swap(&array[i], &array[partition_index]);
			partition_index++;
		}
	}

	swap(&array[partition_index], &array[size - 1]);

	return (partition_index);
}

/**
 * quick_sort - sorts an array using the quicksort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t partition_index = partition(array, size);

		if (partition_index > 0)
		{
			quick_sort(array, partition_index);
		}

		quick_sort(array + partition_index + 1, size - partition_index - 1);
	}
}
