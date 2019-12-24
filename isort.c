#include <stdio.h>
#include "insertion_sort.h"
#define AMOUNT 50

int main()
{
	int arraySize = AMOUNT, i;
	int arr[AMOUNT] = {0};
	printf("Write down the %d numbers to sort: ", arraySize);
	for(i = 0; i < arraySize; i++)
	{
		scanf("%d", (arr + i));
	}
	
	insertion_sort(arr, arraySize);
	
	printf("\n");
	for(i = 0; i < (arraySize - 1) ; i++)
	{
		printf("%d,", *(arr + i));
	}
	printf("%d", *(arr + arraySize - 1) );
	
	return 0;
}