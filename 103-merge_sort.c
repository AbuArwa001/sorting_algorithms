#include "sort.h"
/**
 * printArray - Prints the elements of an array.
 * @label: Label to be printed before the array.
 * @arr: Array to be printed.
 * @length: Length of the array.
 */
void printArray(const char *label, int *arr, int length)
{
	int k;

	printf("[%s]: ", label);

	for (k = 0; k < length; k++)
	{
		printf("%d", arr[k]);

		if (k < length - 1)
		{
			printf(", ");
		}
	}

	printf("\n");
}
/**
 * TopDownMerge - Merges two halves of an array.
 * @arrayB: Temporary array for merging.
 * @iBegin: Starting index of the left subarray.
 * @iMiddle: Ending index of the left subarray
 *           and starting index of the right subarray.
 * @iEnd: Ending index of the right subarray.
 * @array: Original array to be merged.
 */
void TopDownMerge(int *arrayB, int iBegin, int iMiddle, int iEnd, int *array)
{
	int i = iBegin, j = iMiddle, k = 0, l = 0, r = 0;
	int *left = malloc(sizeof(int) * iEnd), *right = malloc(sizeof(int) * iEnd);

	/* While there are elements in the left or right runs... */
	printf("Merging...\n");

	for (k = iBegin; k < iEnd; k++)
	{
		/* If left run head exists and is <= existing right run head. */
		if (i < iMiddle && (j >= iEnd || array[i] <= array[j]))
		{
			left[l] = array[i];
			arrayB[k] = array[i];
			i = i + 1;
			l++;
		}
		else
		{
			right[r] = array[j];
			arrayB[k] = array[j];
			j = j + 1;
			r++;
		}
	}

	printArray("left", left, l);
	printArray("right", right, r);
	printf("[Done]: ");

	for (k = iBegin; k < iEnd; k++)
	{
		printf("%d", arrayB[k]);

		if (k < iEnd - 1)
			printf(", ");
	}

	printf("\n");
	free(left);
	free(right);
}

/**
 * TopDownSplitMerge - Splits and merges the array using the top-down approach.
 * @arrayB: Temporary array for merging.
 * @iBegin: Starting index of the subarray.
 * @iEnd: Ending index of the subarray.
 * @array: Original array to be sorted.
 */
void TopDownSplitMerge(int *arrayB, int iBegin, int iEnd, int *array)
{
	int iMiddle = 0;

	if (iEnd - iBegin <= 1) /* If run size == 1, consider it sorted. */
		return;

	/* Split the run longer than 1 item into halves. */
	iMiddle = (iEnd + iBegin) / 2; /* iMiddle = mid point */

	/* Recursively sort both runs from array A[] into B[]. */
	TopDownSplitMerge(array, iBegin,  iMiddle, arrayB); /* Sort the left run */
	TopDownSplitMerge(array, iMiddle,    iEnd, arrayB); /* Sort the right run */

	/* Merge the resulting runs from array B[] into A[]. */
	TopDownMerge(arrayB, iBegin, iMiddle, iEnd, array);
}

/**
 * CopyArray - Copies elements from one array to another.
 * @array: Source array.
 * @iBegin: Starting index.
 * @iEnd: Ending index.
 * @arrayB: Destination array.
 */
void CopyArray(int *array, int iBegin, int iEnd, int *arrayB)
{
	int k = 0;

	for (k = iBegin; k < iEnd; k++)
		arrayB[k] = array[k];
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *arrayB = NULL;

	if (array == NULL || size <= 1)
	{
		return;
	}

	arrayB = malloc(size * sizeof(int));

	/* One-time copy of A[] to B[] */
	CopyArray(array, 0, size, arrayB);
	TopDownSplitMerge(array, 0, size, arrayB);
	free(arrayB);
}
