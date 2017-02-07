#include <stdio.h>
#include "useful_heap.h"

// 오름차순 정렬을 위한 문장
int priority_comparision(int n1, int n2)
{
	return n2-n1;
//	return n1-n2;
}

// 작성중
void heap_sort(int arr[], int n, priority_comp pc)
{
	struct heap heap;
	int i;

	heap_init(&heap, pc);

	// 정렬 대상을 가지고 힙을 구성한다.
	for(i = 0; i < n; i++)
		heap_insert(&heap, arr[i]);

	// 순서대로 하나씩 꺼내서 정렬을 완성한다.
	for(i = 0; i < n; i++)
		arr[i] = heap_delete(&heap);
}

int main(void)
{
	int arr[5] = {4, 5, 2, 3, 1};
	int i;

	heap_sort(arr, sizeof(arr)/sizeof(int), pri_comp);

	for(i = 0; i < 5; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
