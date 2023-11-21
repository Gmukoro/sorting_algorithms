#include "sort.h"

/**
 * swap_ints - A program that waps two ints in an array.
 * @a: The first int to swapped.
 * @b: The second int to swapped.
 */
void swap_ints(int *a, int *b)
{
	int p;

	p = *a;
	*a = *b;
	*b = p;
}

/**
 * selection_sort - A program that sorts an array of ints in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of ints.
 * @size: The size of the arr.
 *
 * Description: Prints array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *smal;
	size_t j, t;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		smal = array + j;
		for (t = j + 1; t < size; t++)
			smal = (array[t] < *smal) ? (array + t) : smal;

		if ((array + j) != smal)
		{
			swap_ints(array + j, smal);
			print_array(array, size);
		}
	}
}
