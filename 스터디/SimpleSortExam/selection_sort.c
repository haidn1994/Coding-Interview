#include <stdio.h>

void selection_sort(int arr[], int n)
{
	int i,j;
	int max_idx;
	int temp;

	for(i = 0; i < n-1; i++){
		max_idx = i;
		
		// 최소값을 탐색한다.
		for(j = i+1; j < n; j++){
			if(arr[j] < arr[max_idx])
				max_idx = j;
		}

		// 교환
		temp = arr[i];
		arr[i] = arr[max_idx];
		arr[max_idx] = temp;
	}
}

int main(void)
{
	int arr[5] = {4, 5, 2, 3, 1};
	int i;

	selection_sort(arr, sizeof(arr)/sizeof(int));

	for(i = 0; i < 5; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
