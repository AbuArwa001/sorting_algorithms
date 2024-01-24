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
 * @original_size: original size of the array
 * @org_array: ariginal array
 * Return: index of the pivot after partitioning
 */
size_t partition(int *array, size_t size, size_t original_size, int *org_array)
{
	int pivot = array[size - 1];
	size_t partition_index = 0, i = 0;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] < pivot)
		{
			swap(&array[i], &array[partition_index]);
			if (&array[i] != &array[partition_index])
			{
				print_array(org_array, original_size);
			}
			partition_index++;
		}
	}
	swap(&array[partition_index], &array[size - 1]);
	if (&array[size - 1] != &array[partition_index])
	{
		print_array(org_array, original_size);
	}

	return (partition_index);
}
/**
 * q_sort - sorts an array using the quicksort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * @org_size: original size of the array
 * @org_array: ariginal array
 */
void q_sort(int *array, size_t size, size_t org_size, int *org_array)
{
	if (size > 1)
	{
		size_t p_index = partition(array, size, org_size, org_array);

		if (p_index > 0)
		{
			q_sort(array, p_index, org_size, org_array);
		}
		q_sort(array + p_index + 1, size - p_index - 1, org_size, org_array);
	}
}
/**
 * quick_sort - sorts an array using the quicksort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	size_t original_size = size;
	int *org_array = array;

	if (array == NULL || size <= 1)
	{
		return;
	}

	q_sort(array, size, original_size, org_array);
}
