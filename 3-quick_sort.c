#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @x: the 1st integer to swap
 * @y: the 2ond integer
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - divides an array or a partition into two parts and returns
 * The pivot index using the Lomuto partition scheme
 * @array: the array to sort or segregate
 * @lo: the low index of the array to partition
 * @hi: the high index of the array to partition
 * @size: the size of the array to segregate
 *
 * Return: the centre index
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1, j;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[hi])
	{
		swap(&array[i + 1], &array[hi]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort - sorts an array of integers in ascending order
 * Using the Quick sort algorithm and Lomuto partition scheme
 * @array: The array to sort
 * @lo: the low index of the array to sort
 * @hi: the high index of the array to sort
 * @size: the size of the array to be sorted
*/
void quicksort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quicksort(array, lo, p - 1, size);
		quicksort(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * Using the Quick sort algorithm and Lomuto partition scheme
 * @array: The array to sort.
 * @size: The array size to be sorted
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
