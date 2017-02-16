/*
	병합 정렬의 진행 순서	

    1. 분할(Divide)
	2. 정복(Conquer)
	3. 결합(Combine)

	최선이든 최악이든 관계없이 언제나 big-O가 n*log(2)이라는 점이 매력적인 정렬 방법이다.
	하지만 배열에서는 임시 메모리가 2배로 필요하다는 단점이 있다.

	그러나 연결 리스트에서는 이 단점을 상쇄 가능하므로, 배열 정렬보다 더 좋은 성능을 보인다.
 */

#include <stdio.h>
#include <stdlib.h>

void merge_two_area(int arr[], int left, int mid, int right)
{
	int first_idx = left;
	int rear_idx = mid+1;
	int i;

	// 정렬에 필요한 메모리는 동적할당을 통해서 마련한다.
	int *sort_arr = (int *)malloc(sizeof(int)*(right+1));
	int sort_idx = left;

	while(first_idx <= mid && rear_idx <= right){
		if(arr[first_idx] <= arr[rear_idx])
			sort_arr[sort_idx] = arr[first_idx++];
		else
			sort_arr[sort_idx] = arr[rear_idx++];

		sort_idx++;
	}

	if(first_idx > mid)
		for(i = rear_idx; i <= right; i++, sort_idx++)
			sort_arr[sort_idx] = arr[i];
	else
		for(i = first_idx; i <= mid; i++, sort_idx++)
			sort_arr[sort_idx] = arr[i];

	for(i = first_idx; i <= mid; i++, sort_idx++)
		arr[i] = sort_arr[i];

	free(sort_arr);
}


// 병합 정렬은 재귀적인 특징이 살아있는 정렬 알고리즘이다.
void merge_sort(int arr[], int left, int right)
{
	int mid;

	// 배열 기반에 서로 빼는 연산이 없으므로,
	// 이 연산은 음수 아닌 정수에 닫혀 있다.
	// 따라서 (x + y) >> 1 이 제일 적당하다.
	if(left < right){
		// 중간 지점을 계산한다.
		mid = (left+right) >> 1;

		// 둘로 나눠서 각각을 정렬한다.
		merge_sort(arr, left, mid);
		merge_sort(arr, mid+1, right);

		// 정렬된 두 배열을 병합한다.
		merge_two_area(arr, left, mid, right);
	}
}

int main(void)
{
	int arr[1000000] = {0,};
	int i, count;

	scanf("%d", &count);

	for(i = 0; i < count; i++)
		scanf("%d", &arr[i]);

	// 배열 arr의 전체 영역 정렬
	merge_sort(arr, 0, sizeof(arr)/sizeof(int)-1);

	for(i = 0; i < count; i++)
		printf("%d\n", arr[i]);
	return 0;
}
