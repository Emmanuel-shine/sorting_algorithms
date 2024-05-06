#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array and prints the array
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
    if (*a != *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
        printf(", ");
        print_array(b, 2);
    }
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array to partition
 * @size: Size of the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * Return: Partition index
 */
int lomuto_partition(int *array, int size, int low, int high)
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
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

/**
 * quicksort - Recursive function to implement quicksort
 * @array: Array to be sorted
 * @size: Size of the array
 * @low: Starting index of the array
 * @high: Ending index of the array
 */
void quicksort(int *array, size_t size, int low, int high)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, size, low, high);

        quicksort(array, size, low, pi - 1);
        quicksort(array, size, pi + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quicksort(array, size, 0, size - 1);
}

