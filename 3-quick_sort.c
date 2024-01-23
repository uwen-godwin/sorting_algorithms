#include "sort.h"

/**
* quick_sort - Sorts an array of integers in ascending order using Quick sort
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quicksort_recursive(array, 0, size - 1, size);
}

/**
* quicksort_recursive - Recursive function to perform Quick sort
* @array: The array to be sorted
* @low: The low index of the partition
* @high: The high index of the partition
* @size: Number of elements in the array
*/
void quicksort_recursive(int *array, int low, int high, size_t size)
{
int pivot;

if (low < high)
{
pivot = partition(array, low, high, size);
quicksort_recursive(array, low, pivot - 1, size);
quicksort_recursive(array, pivot + 1, high, size);
}
}

/**
* partition - Partitions the array for Quick sort
* @array: The array to be sorted
* @low: The low index of the partition
* @high: The high index of the partition
* @size: Number of elements in the array
*
* Return: The index of the pivot element
*/
int partition(int *array, int low, int high, size_t size)
{
int pivot, i, j, temp;

pivot = array[high];
i = low - 1;

for (j = low; j <= high - 1; j++)
{
if (array[j] <= pivot)
{
i++;
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
}

temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
print_array(array, size);

return (i + 1);
}
