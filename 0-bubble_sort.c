#include "sort.h"

/**
 * add_to_list - adds elements to list
 *              in ascending order using the Bubble sort algorithm
 * @head: head of the list
 * @num: int to be added
 * Return: returns the new node added
*/
listint_t *add_to_list(listint_t **head, const int num)
{
	listint_t *temp = malloc(sizeof(listint_t)), *h = *head;
	int *p;

	if (temp == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	p = (int *)&temp->n;
	*p = num;
	temp->next = NULL;
	temp->prev = NULL;

	if (*head == NULL)
	{
		*head = temp;
		return (temp);
	}
	else
	{
		while (h->next != NULL)
		{
			h = h->next;
		}

		temp->prev = h;
		h->next = temp;
	}

	return (temp);
}
/**
 * create_list_from_array - creates a list
 * @array: array to be converted to list
 * @size: size of the array
 * Return: returns the head of the list
*/
listint_t *create_list_from_array(int *array, size_t size)
{
	listint_t *head = NULL;
	size_t j;

	for (j = 0; j < size; j++)
	{
		add_to_list(&head, array[j]);
	}

	return (head);
}
/**
 * bubble_sort - sorts an array of integers
 *              in ascending order using the Bubble sort algorithm
 * @array: arrat to be sorted
 * @size: size of  the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int temp = 0;
	listint_t **h = malloc(sizeof(listint_t));

	for (i = 0; i < size; i++)
	{
		add_to_list(h, array[i]);
	}

	for (j = 0; j < size; j++)
	{

		for (i = 0 ; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp  = array[i];
				array[i]  = array[i + 1];
				array[i + 1] = temp;
				*h = create_list_from_array(array, size);
				print_list(*h);
			}
		}


	}
}
/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;

	while (list)
	{
		if (i > 0)
			printf(", ");

		printf("%d", list->n);
		++i;
		list = list->next;
	}

	printf("\n");
}
