#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers using the
 * Jump search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in array.
 * @value: Value to search for.
 *
 * Return: The first index where value is located, or -1 on failure.
 */
int jump_search(int *array, size_t size, int value)
{
	int jump = sqrt(size), left = 0, right = 0;

	if (array == NULL || size == 0)
		return (-1);

	while (right < (int)size && array[right] < value)
	{
		left = right;
		right += jump;

		printf("Value checked array[%d] = [%d]\n", left, array[left]);
	}

	printf("Value found between indexes [%d] and [%d]\n", left, right);

	right = right < (int)size ? right : (int)size - 1;

	while (left <= right)
	{
		printf("Value checked array[%d] = [%d]\n", left, array[left]);

		if (array[left] == value)
			return (left);

		left++;
	}

	return (-1);
}

