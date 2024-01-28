#include "sort.h"

/**
 * _counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm with consideration for a specific digit
 * @array: array to be sorted
 * @size: size of the array
 * @mod: the digit position to consider (units, tens, hundreds, etc.)
 */
void _counting_sort(int *array, size_t size, int mod)
{
	int k1 = 0, j = 0, l = 0;
	size_t i =  0, k = 0;
	int *output = malloc(sizeof(int) * size), *count = NULL;

	if (array == NULL || size <= 1)
	{
		free(output);
		return;
	}

	/* // Determine the maximum value to establish the range */
	for (i = 0; i < size; i++)
	{
		if (array[i] > l)
			k = l = array[i];
	}

	k1 = k + 1;
	count = malloc(sizeof(int) * k1);
	/* // Initialize count array */
	for (i = 0; i <= k; i++)
		count[i] = 0;
	/* // Count occurrences of each digit */
	for (i = 0; i < size; i++)
		count[(array[i] / mod) % 10]++;
	/* // Modify count array to store actual position */
	for (i = 1; i <= k; i++)
		count[i] = count[i] + count[i - 1];
	/* // Build the output array based on the count array */
	for (j = size - 1; j >= 0; j--)
	{
		count[(array[j] / mod) % 10] = count[(array[j] / mod) % 10] - 1;
		output[count[(array[j] / mod) % 10]] = array[j];
	}
	/* // Copy the sorted elements back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = array[0];
	size_t i = 0;

	/* // Find the maximum value in the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (i = 1; max / i > 0; i *= 10)
	{
		_counting_sort(array, size, i);
		print_array(array, size);
	}
}
