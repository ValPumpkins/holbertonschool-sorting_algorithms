#include "sort.h"


/**
 * lomuto - lomutp technique, chose a pivot,
 * here the last element of a array
 * @array: pointer to first element of array
 * @low: element of array
 * @high: element of array
 * @size: number of element in a array
 * Return: next sorting element location
 */

size_t lomuto(int *array, int low, int high, size_t size)
{
	int index, index0, pivot, swap;

	index = low - 1;
	pivot = array[high];

	for (index0 = low; index0 < high; ++index0)
	{
		if (array[index0] < pivot)
		{
			index++;
			if (index != index0)
			{
				swap = array[index];
				array[index] = array[index0];
				array[index0] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[index + 1])
	{
		swap = array[high];
		array[high] = array[index + 1];
		array[index + 1] = swap;
		print_array(array, size);
		/* set the high index value to its sorted position */
	}
	return (index + 1); /* returns the next sorting element */
}

/**
 * quicksort - sorts an array of integers in ascending
 *  order using the Quick sort algorithm
 * @array: array of integer
 * @start: the starter
 * @end: end of array
 * @size: size of array
*/

void quicksort(int *array, int start, int end, size_t size)
{
	size_t pivot;

	if (start < end)
	{
		pivot = lomuto(array, start, end, size);
		quicksort(array, start, pivot - 1, size);
		quicksort(array, pivot + 1, end, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending
 *  order using the Quick sort algorithm
 * @array: array if integer
 * @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (!array)
		return;
	quicksort(array, 0, size - 1, size);
}
