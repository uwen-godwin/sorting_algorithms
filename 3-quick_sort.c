#include "sort.h"

/**
* swap - swaps two elements in an array
* @a: pointer to first element
* @b: pointer to second element
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
* lomuto_partition - Lomuto partition scheme for Quick sort
* @array: array to be partitioned
* @low: starting index of the partition
* @high: ending index of the partition
* @size: size of the array
* Return: index of the pivot after partitioning
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j;

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
* quick_sort_recursive - recursive function to implement Quick sort
* @array: array to be sorted
* @low: starting index
* @high: ending index
* @size: size of the array
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
if (low < high)
{
int partition_index = lomuto_partition(array, low, high, size);

quick_sort_recursive(array, low, partition_index - 1, size);
quick_sort_recursive(array, partition_index + 1, high, size);
}
}

/**
* quick_sort - sorts an array of integers in ascending order using Quick sort
* @array: array to be sorted
* @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_recursive(array, 0, size - 1, size);
}
