#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm
 * @array: the array to sort
 * @size: the number of data to sort
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap;

	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
		if (!swap)
			break;
	}
}
