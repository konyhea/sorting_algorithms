#include "sort.h"
/**
 * initial_gap - Computes the initial gap for Shell sort using Knuth sequence
 * @size: Size of the array
 * Return: Initial gap
 */
size_t initial_gap(size_t size)
{
    size_t gap = 1;
    while (gap < size)
        gap = gap * 3 + 1;
    return (gap / 3);
}

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
    size_t i, j, gap;

    if (array == NULL || size < 2)
        return;

    for (gap = initial_gap(size); gap > 0; gap = (gap - 1) / 3)
    {
        for (j = gap; j < size; j++)
        {
            for (i = j; i >= gap && array[i] < array[i - gap]; i -= gap)
            {
                swap(&array[i], &array[i - gap]);
            }
        }
        print_array(array, size);
    }
}
