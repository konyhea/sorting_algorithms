#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
    int *count = NULL;
    int *output = NULL;
    int max = INT_MIN;
    size_t i;

    // Find the maximum element in the array
    for (i = 0; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // Create a counting array of size max+1 initialized to zeros
    count = (int *)calloc(max + 1, sizeof(int));
    if (count == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Count the occurrences of each element
    for (i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Print the counting array
    printf("Counting array: ");
    print_array(count, max + 1);

    // Compute the prefix sum
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Allocate memory for the output array
    output = (int *)malloc(size * sizeof(int));
    if (output == NULL) {
        printf("Memory allocation failed\n");
        free(count);
        return;
    }

    // Place the elements in the output array according to the count
    for (i = size - 1; i < size; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the output array to the original array
    for (i = 0; i < size; i++) {
        array[i] = output[i];
        print_array(array, size);
    }

    // Free memory
    free(count);
    free(output);
}
