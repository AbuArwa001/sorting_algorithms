#include "sort.h"
/**
 * counting_sort - sorts an array of integers
 *                 in ascending order using the Counting sort algorithm
 * @array: array to be sorted;
 * @size: size of the array
*/
void counting_sort(int *array, size_t size)
{
	int k1 = 0, j = 0, l = 0;
	size_t i =  0, k = 0;
	int *output = malloc(sizeof(int) * size), *count = NULL;

	if (array == NULL || size == 0)
	{
		free(output);
		return;
	}
	for (i = 0; i < size; i++)
	{
		if (array[i] > l)
			k = l = array[i];
	}
	k1 = k + 1;
	count = malloc(sizeof(int) * k1);
	for (i = 0; i <= k; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= k; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, k + 1);
	for (j = size - 1; j >= 0; j--)
	{
		/**
		 *count[i] = count[i] - 1;
		 * val = array[i];
		 * index = count[val] - 1;
		 * count[array[i]]
		 * count[val] = count[val] - 1;
		 * output[index] = val;
		 */
		count[array[j]] = count[array[j]] - 1;
		output[count[array[j]]] = array[j];
	}
	for (i = 0 ; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
