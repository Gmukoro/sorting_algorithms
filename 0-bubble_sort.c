#include "sort.h"
#include <stddef.h>

/**
 * swap_ints - A program that swaps two ints in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int p;

	p = *a;
	*a = *b;
	*b = p;
}

/**
 * bubble_sort - Sorts an array of ints in ascending order.
 * @array: An array of ints to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap correctly.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	i = 0;
	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
