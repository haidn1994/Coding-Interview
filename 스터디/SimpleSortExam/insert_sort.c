#include <stdio.h>

void insertion_sort(int arr[], int n)
{
	int i,j;
	int insert_data;

	for(i = 1; i < n; i++){
		insert_data = arr[i];		// 정렬 대상을 insert_data에 저장

		for(j = i-1; j >= 0; j--){
			if(arr[j] > insert_data)
				arr[j+1] = arr[j];	// 비교대상 한 칸 뒤로 밀기
			else
				break;
		}

		arr[j+1] = insert_data;		// 찾은 위치에 정렬대상 삽입!
	}
}

int main(void)
{
	int arr[5] = {4, 5, 2, 3, 1};
	int i;

	insert_sort(arr, sizeof(arr)/sizeof(int));

	for(i = 0; i < 5; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}

