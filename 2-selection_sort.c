#include "sort.h"
/**
 * selection_sort - sorts by selectin least elements
 *                  and placing them infron
 * @array: array to be sorted
 * @size: size of the array
*/
void selection_sort(int *array, size_t size)
{
	int least = 0, temp = 0, j = 0, i = 0, swapped = 0;

	for (j = 0; j < size; j++)
	{
		swapped = 0;
		least = array[j];

		for (int i = j + 1; i < size; i++)
		{
			if (array[i] < least)
			{
				temp = least;
				least = array[i];
				array[i] = temp;
				swapped = 1;
			}

		}

		if (swapped == 1)
		{
			array[j] = least;
		}

	}


}
