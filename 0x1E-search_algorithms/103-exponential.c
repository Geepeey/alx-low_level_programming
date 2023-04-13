#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 *
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: The first index where value is located or -1 if value is not
 * present in array or if array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
		size_t bound = 1, left, right, i;

		if (array == NULL || size == 0)
				return (-1);

		while (bound < size && array[bound] < value)
		{
				printf("Value checked array[%lu] = [%d]\n",
						bound, array[bound]);
				bound *= 2;
		}

		left = bound / 2;
		right = bound >= size ? size - 1 : bound;

		printf("Value found between indexes [%lu] and [%lu]\n", left, right);

		while (left <= right)
		{
				printf("Searching in array: ");
				for (i = left; i < right; i++)
						printf("%d, ", array[i]);
				printf("%d\n", array[i]);

				i = (left + right) / 2;

				if (array[i] < value)
						left = i + 1;
				else if (array[i] > value)
						right = i - 1;
				else
						return (i);
		}

		return (-1);
}

