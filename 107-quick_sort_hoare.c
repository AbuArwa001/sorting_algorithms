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
 * @lo: starting index
 * @hi: ending index
 * @org_array: original array
 * Return: index of the pivot after partitioning
 */
size_t partition(int *array, size_t lo, size_t hi, int *org_array)
{
    int pivot = array[lo];
    size_t i = lo - 1, j = hi + 1;

    while (1)
    {
        do
        {
            i = i + 1;
        } while (array[i] < pivot);

        do
        {
            j = j - 1;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(org_array, (size_t)hi + 1);
    }
}

/**
 * q_sort - sorts an array using the quicksort algorithm
 * @array: array to be sorted
 * @lo: starting index
 * @hi: ending index
 * @org_array: original array
 */
void q_sort(int *array, size_t lo, size_t hi, int *org_array)
{
    if (lo < hi)
    {
        size_t p_index = partition(array, lo, hi, org_array);

        q_sort(array, lo, p_index, org_array);
        q_sort(array, p_index + 1, hi, org_array);
    }
}

/**
 * quick_sort_hoare - sorts an array using the quicksort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    size_t lo = 0;
    size_t hi = (size_t)size - 1;
    int *org_array = array;

    if (array == NULL || size <= 1)
    {
        return;
    }

    q_sort(array, lo, hi, org_array);
}