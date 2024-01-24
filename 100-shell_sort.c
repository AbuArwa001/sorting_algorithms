#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t h = 1, j, i;
	int temp;

	if (array == NULL || size == 0)
	{
		return;
	}

	/* Calculate the initial gap using the Knuth sequence */
	while (h < size / 3)
	{
		h = 3 * h + 1;
	}

	/* Iterate over gaps and perform insertion sort within each gap */
	while (h > 0)
	{
		for (i = h; i < size; i++)
		{
			temp = array[i];
			j = i;

			/* Perform insertion sort within the gap */
			while (j >= h && array[j - h] > temp)
			{
				array[j] = array[j - h];
				j = j - h;
			}

			array[j] = temp;
		}

		print_array(array, size);
		/* Reduce the gap for the next iteration */
		h /= 3;
	}
}
