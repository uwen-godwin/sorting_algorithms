#include "sort.h"

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

/**
* lomuto_partition - Partitions the array using Lomuto scheme
* @array: The array to be sorted
* @low: Starting index of the partition to be sorted
* @high: Ending index of the partition to be sorted
* @size: Size of the array
*
* Return: Index of the pivot after partitioning
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1, j;

for (j = low; j <= high - 1; j++)
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
* quicksort - Recursive function to perform quicksort
* @array: The array to be sorted
* @low: Starting index of the partition to be sorted
* @high: Ending index of the partition to be sorted
* @size: Size of the array
*/
void quicksort(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot_index = lomuto_partition(array, low, high, size);

quicksort(array, low, pivot_index - 1, size);
quicksort(array, pivot_index + 1, high, size);
}
}

/**
* quick_sort - Sorts an array of integers using Quick sort algorithm
* @array: The array to be sorted
* @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quicksort(array, 0, size - 1, size);
}
