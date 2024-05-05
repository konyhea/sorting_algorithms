#include "sort.h"

/**
 * selection_sort - selection sort algo
 * @array: lidt of data to sort with algo
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j,  min;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != 1)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
