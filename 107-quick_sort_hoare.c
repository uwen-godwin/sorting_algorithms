#include "sort.h"

void recursive_quick_sort_hoare(int *array, int low, int high, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the Quick sort algorithm (Hoare partition scheme)
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    recursive_quick_sort_hoare(array, 0, size - 1, size);
}

/**
 * recursive_quick_sort_hoare - Recursively sorts a partition of an array
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: The size of the array
 */
void recursive_quick_sort_hoare(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, low, high, size);

        recursive_quick_sort_hoare(array, low, pivot, size);
        recursive_quick_sort_hoare(array, pivot + 1, high, size);
    }
}

/**
 * hoare_partition - Partitions the array using the Hoare scheme
 * @array: The array to be partitioned
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
