#include "sort.h"

/**
 * merge_sort - Sorts an array of integers using Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_recursive(array, size);
}

/**
 * merge_recursive - Recursively divides and merges the array
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_recursive(int *array, size_t size)
{
    if (size < 2)
        return;

    size_t mid = size / 2;
    int *left = array;
    int *right = array + mid;

    merge_recursive(left, mid);
    merge_recursive(right, size - mid);

    merge(array, left, mid, right, size - mid);
}

/**
 * merge - Merges two subarrays into a single sorted array
 * @array: Array to be sorted
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *temp = malloc((left_size + right_size) * sizeof(int));

    if (temp == NULL)
        return;

    printf("Merging...\n");

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            temp[k++] = left[i++];
        else
            temp[k++] = right[j++];
    }

    while (i < left_size)
        temp[k++] = left[i++];

    while (j < right_size)
        temp[k++] = right[j++];

    for (i = 0; i < left_size + right_size; i++)
    {
        array[i] = temp[i];
        if (i < left_size)
            printf("[left]: %d\n", left[i]);
        else
            printf("[right]: %d\n", right[i - left_size]);
    }

    printf("[Done]: ");
    print_array(array, left_size + right_size);

    free(temp);
}
