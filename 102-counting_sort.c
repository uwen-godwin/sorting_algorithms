#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using Counting sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Find the maximum value to determine the range */
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create counting array and initialize to zero */
    int *count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    for (int i = 0; i <= max; i++)
        count[i] = 0;

    /* Count occurrences of each element */
    for (size_t i = 0; i < size; i++)
        count[array[i]]++;

    /* Update array with sorted values from counting array */
    size_t i = 0, j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            array[j++] = i;
            count[i]--;
        }
        else
            i++;
    }

    /* Print counting array */
    for (i = 0; i <= max; i++)
        printf("%d, ", count[i]);

    free(count);
}
