#include "sort.h"

/**
* find_max_value - Find the maximum value in an array of integers.
* @arr: An array of integers.
* @len: The length of the array.
*
* Return: The maximum integer in the array.
*/
int find_max_value(int *arr, int len)
{
int max_val, index;

for (max_val = arr[0], index = 1; index < len; index++)
{
if (arr[index] > max_val)
max_val = arr[index];
}

return (max_val);
}

/**
* counting_sort - Sort an array of integers in ascending order
*                 using the counting sort algorithm.
* @arr: An array of integers.
* @len: The length of the array.
*
* Description: Prints the counting array after setting it up.
*/
void counting_sort(int *arr, size_t len)
{
int *count_array, *sorted_array, max_val, index;

if (arr == NULL || len < 2)
return;

sorted_array = malloc(sizeof(int) * len);
if (sorted_array == NULL)
return;

max_val = find_max_value(arr, len);
count_array = malloc(sizeof(int) * (max_val + 1));
if (count_array == NULL)
{
free(sorted_array);
return;
}

for (index = 0; index < (max_val + 1); index++)
count_array[index] = 0;

for (index = 0; index < (int)len; index++)
count_array[arr[index]] += 1;

for (index = 0; index < (max_val + 1); index++)
count_array[index] += count_array[index - 1];

print_array(count_array, max_val + 1);

for (index = 0; index < (int)len; index++)
{
sorted_array[count_array[arr[index]] - 1] = arr[index];
count_array[arr[index]] -= 1;
}

for (index = 0; index < (int)len; index++)
arr[index] = sorted_array[index];

free(sorted_array);
free(count_array);
}
