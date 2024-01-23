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
size_t partition(int *array, size_t size, size_t original_size,int *org_array)
{
	int pivot = array[size - 1];
	size_t partition_index = 0, i = 0;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] < pivot)
		{
			if (array[i] != array[partition_index])
			{
				swap(&array[i], &array[partition_index]);
				print_array(org_array, original_size);
			}
			partition_index++;
		}
	}

	
	swap(&array[partition_index], &array[size - 1]);
	print_array(org_array, original_size);
	return (partition_index);
}
void q_sort(int *array, size_t size, size_t original_size,int *org_array)
{
	if (size > 1)
	{
		size_t partition_index = partition(array, size, original_size,org_array);

		if (partition_index > 0)
		{
			q_sort(array, partition_index, original_size, org_array);
		}
		q_sort(array + partition_index + 1, size - partition_index - 1, original_size, org_array);
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
	q_sort(array, size,original_size, org_array);
}
