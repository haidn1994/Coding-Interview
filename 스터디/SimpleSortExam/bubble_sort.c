/*
	배열 기반의 거품 정렬 간단 예제	
 */
#include <stdio.h>

void bubble_sort(int arr[], int n)
{
	int i, j;
	int temp;

	for(i = 0; i < n-1; i++){
		for(j = 0; j < (n-i)-1; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(void)
{
	int arr[5] = {4, 2, 5, 1, 3};
	int i;

	bubble_sort(arr, sizeof(arr)/sizeof(int));

	for(i = 0; i < 5; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}
