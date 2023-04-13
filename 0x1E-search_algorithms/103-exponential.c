#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * using the Exponential search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The first index where value is located, or -1 if value is not
 *		   present in array or if array is NULL.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, low, high;

	if (array == NULL || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = bound >= size ? size - 1 : bound;

	printf("Value found between indexes [%lu] and [%lu]\n", low, high);

	while (low <= high)
	{
		size_t mid = (low + high) / 2;

		printf("Searching in array: ");
		for (size_t i = low; i < high; ++i)
			printf("%d, ", array[i]);
		printf("%d\n", array[high]);

		if (array[mid] < value)
			low = mid + 1;
		else if (array[mid] > value)
			high = mid - 1;
		else
			return (mid);
	}

	return (-1);
}

