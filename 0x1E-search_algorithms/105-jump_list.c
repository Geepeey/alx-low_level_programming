#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list of integers
 * using the Jump search algorithm.
 *
 * @list: A pointer to the head of the list to search in.
 * @size: The number of nodes in the list.
 * @value: The value to search for.
 *
 * Return: A pointer to the first node where value is located.
 *		   NULL if the value is not found or the head is NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *left = NULL, *right = NULL;
	size_t jump = 0;

	if (list == NULL || size == 0)
		return (NULL);

	jump = sqrt(size);
	right = left = list;

	while (right->n < value && right->next != NULL)
	{
		left = right;
		right = right->next;
		printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
		while (right->n < value && right->next != NULL && jump--)
		{
			left = right;
			right = right->next;
			printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
		}
		jump = sqrt(size);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", left->index, right->index);

	while (left->index < right->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);
		if (left->n == value)
			return (left);
		left = left->next;
	}

	printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);
	if (left->n == value)
		return (left);

	return (NULL);
}

