/*
	여기 나오는 모든 코드는 배열 기반으로 만들어졌습니다.

	참고로 exit()가 있어야 프로세스가 종료되는데, 이는 stdlib.h에 있다.
 */

#include <stdio.h>
#include <stdlib.h>

/*
	순차 탐색의 시간 복잡도는 O(n)이다.

 	또한 순차 탐색의 경우 자료구조에 크게 의존하지 않고,
	정렬유무에도 거의 의존하지 않는다. 
 */
int linear_search(int ar[], int len, int target) // 순차 탐색 알고리즘이 적용된 함수
{

	int i;
	for(i = 0; i < len; i++) 
		if(ar[i] == target)
			return i; // 찾은 대상의 인덱스를 반환하는 값

	return -1;	// 찾지 못했음을 의미하는 값 반환

}

void print_idx(int idx)
{
	if(idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);
}


int main (void)
{
	int arr[] = {3, 5, 2, 4, 9};
	int idx;	// 타겟의 인덱스

	int menu = 0;
	int user_input = 0;

	int i;

	for(;;){
		
		printf("메뉴: 1.순차 탐색하기 2.배열 원소 보기 3.종료\n");
		scanf("%d", &menu);

		switch(menu){
			case 1:
				printf("찾을 정수를 입력하세요\n");
				scanf("%d", &user_input);
				
				idx = linear_search(arr, sizeof(arr)/sizeof(int), user_input);
				print_idx(idx);
				break;
			case 2:
				printf("프로세스 배열:");
				for(i = 0; i < sizeof(arr)/sizeof(int); i++)
					printf("%d ", arr[i]);
				printf("\n");
				break;
			case 3:
				printf("프로세스를 종료합니다.\n");
				goto exit;
		}
	}

exit:
	exit(1); // 1일때 프로세스 종료한다. 자세한 사항은 man 2 exit로 알아볼것
}

	


		
