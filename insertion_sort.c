#include "insertion_sort.h"

int shift_element(int* arr, int i)
{
	while(i != 0)
	{
		*(arr + i) = *(arr + (i-1) );
		i--;
	}
	return 0;
}


size_t minInArray(int* arr, int len)
{
	size_t minIndex = 0, i;
	for(i = 1; i < len; i++)
	{
		if( *(arr + i) < *(arr + minIndex) )
		{
			minIndex = i;
		}
	}
	
	return minIndex;
}


int insertion_sort(int* arr, int len)
{
	size_t index;								//Saves the beginnig index of the remaining unsorted array.
	for(index = 0; index < len; index++)
	{
		int* arrUnsorted = (arr + index);		//Pointer to the remaining unsorted array beginnig. 
		size_t minIndex = minInArray(arrUnsorted, (len - index) );				//Saves the minimum organ index of the remaining unsorted array =  the sorted array's next organ index.
		int min = *(arr + minIndex);
		shift_element(arrUnsorted, minIndex);
		*arrUnsorted = min;
	}
	
	return 0;
}