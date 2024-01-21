#include "sort.h"

/**
 * add_to_list - adds elements to list
 * @head: head of the list
 * @num: int to be added
 * @lNode: the last node
 * Return: returns the new node added
*/
listint_t *add_to_list(listint_t **head, listint_t *lNode, const int num)
{
	listint_t *temp = malloc(sizeof(listint_t));
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
		temp->prev = lNode;
		lNode->next = temp;
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
	listint_t *lNode = head;

	for (j = 0; j < size; j++)
	{
		lNode = add_to_list(&head, lNode, array[j]);

	}

	return (head);
}

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
				*h = create_list_from_array(array, size);
				print_list(*h);
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

/**
 * print_list - Prints a list of integers
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
