#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list);

/*
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size);
/**
 * bubble_sort - sorts an array of integers
 *              in ascending order using the Bubble sort algorithm
 * @array: arrat to be sorted
 * @size: size of  the array
*/
void bubble_sort(int *array, size_t size);
/**
* vinsertion_sort_list - sort a list with insertion method
* @list: a list to sort
*/
void insertion_sort_list(listint_t **list);
/**
 * selection_sort - sorts by selectin least elements
 *                  and placing them infron
 * @array: array to be sorted
 * @size: size of the array
*/
void selection_sort(int *array, size_t size);
/**
 * quick_sort - sorts an array in segments and recursion
 * @array: array to be sorted
 * @size: size of the array
*/
void quick_sort(int *array, size_t size);
/*
 * shell_sort - sorts an array of integers in ascending
 *              order using the Shell sort algorithm,
 *               using the Knuth sequence
 * @array: array to be sorted
 * @size: size of the array
*/
void shell_sort(int *array, size_t size);
/**
 * cocktail_sort_list - sorts a doubly
 *          linked list using Cocktail Sort algorithm
 * @list: double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list);
#endif
