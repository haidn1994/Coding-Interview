/*
	배열 기반의 거품 정렬 간단 예제	
 */
#include <stdio.h>
#include <string.h>

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
	int number_of_line;
	
	int *arr = (int*)malloc(sizeof(int) * number_of_line);
	(int*)memset(arr, 0, sizeof(int) * number_of_line); 	

	int i;
	int input;

	scanf_s("%d", number_of_line);

	for(i = 0; i < number_of_line; i++){
		scanf_s("%d", &input);
		arr[i] = input;
	}

	bubble_sort(arr, number_of_line);

	for(i = 0; i < number_of_line; i++)
		printf("%d\n", arr[i]);

	return 0;
}
