#include "sort.h"

/**
 * partition - Partitions the array and returns the partition index
 * @array: The array to be partitioned
 * @low: The lower bound of the partition
 * @high: The upper bound of the partition
 * @size: Size of the array
 * Return: Index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high]; // Pivot is always the last element
    int i = low - 1; // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, size);
        }
    }
    swap(&array[i + 1], &array[high]);
    print_array(array, size);
    return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform quicksort
 * @array: The array to be sorted
 * @low: The lower bound of the array
 * @high: The upper bound of the array
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = partition(array, low, high, size);
        quick_sort_recursive(array, low, pi - 1, size);
        quick_sort_recursive(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
