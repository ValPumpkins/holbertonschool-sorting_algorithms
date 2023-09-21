#include "sort.h"

/**
 * shell_sort - sort an array in ascending order
 * using the Knuth sequence
 * @array: pointer to first element in array
 * @size: element in array
*/


void shell_sort(int *array, size_t size)
{
	size_t index, j, gap = 1;
	int temp;

	if (!array || size < 2)
		return;

	gap = gap * 3 + 1;
	while (gap < size)
	{
		for (gap = gap * 3 + 1; gap > 0; gap = (gap - 1) / 3)
		{
			for (index = gap; index < size; index++)
			{
				temp = array[index];
				for (j = index; j >= gap && array[j - gap] > temp; j -= gap)
					array[j] = array[j - gap];
				array[j] = temp;
			}
			print_array(array, size);
		}
		gap = (gap - 1) / 3;
	}
}

