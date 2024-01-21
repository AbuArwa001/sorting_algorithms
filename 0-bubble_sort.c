#include "sort.h"

/**
 * bubble_sort - sorts an array of integers
 * @array: array to be sorted
 * @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp = 0;
	listint_t **h = malloc(sizeof(listint_t));

	if (!array || !size)
		return;
	for (i = 0; i < size; i++)
	{
		int swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}

		if (!swapped)
		{
			break;
		}

	}

	free(*h);
	free(h);
}
