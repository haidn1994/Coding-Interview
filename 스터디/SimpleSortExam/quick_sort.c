#include <stdio.h>

void swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(int arr[], int left, int right)
{
	int pivot = arr[left];	// 피벗의 위치는 가장 왼쪽!
	int low = left;
	int high = right;

	while(low <= high){		// 교차되지 않을 때까지 반복
		// 피벗보다 큰 값을 찾는 과정
		while(pivot > arr[low])
			low++;			// low를 오른쪽으로 이동

		// 피벗보다 작은 값을 찾는 과정
		while(pivot < arr[high])
			high--;			// high를 왼쪽으로 이동

		// 교차되지 않은 상태라면 swap을 실행한다.
		if(low <= high)
			swap(arr, low, high);
	}

	swap(arr, left, high);
	return 0;
}

void quick_sort(int arr[], int left, int right)
{
	if(left <= right){
		int pivot = partition(arr, left, right);	// 둘로 나눠서
		quick_sort(arr, left, pivot-1);				// 왼쪽 영역을 정렬
		quick_sort(arr, pivot+1, right);			// 오른쪽 영역을 정렬
	}
}

int main(void)
{
	int arr[7] = {3, 2, 4, 1, 7, 6, 5};
//	int arr[3] = {3, 3, 3};				// 왜 이렇게 만들었는지는 다음에 설명하겠다.

	int len = sizeof(arr)/sizeof(int);
	int i;

	quick_sort(arr, 0, sizeof(arr)/sizeof(int)-1);

	for(i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}


