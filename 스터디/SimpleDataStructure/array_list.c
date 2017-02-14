/*
	주의점은 cur_position을 조정하는 함수가 
	list_first()와 list_next()말고도 list_display_all()과 list_remove()가 있다는 점이다.
	따라서 list_display_cur_position()을 잘 활용하라.
 */

#include <stdio.h>
#include "array_list.h"

void list_init(struct array_list *plist)
{
	(plist->num_of_data) = 0;	// 리스트에 저장된 데이터의 수는 0이다.
	(plist->cur_position) = -1; // 현재 아무런 위치도 가리키지 않는다.
}// 리스트 초기화

void list_insert(struct array_list *plist, int list_data)
{
	if(plist->num_of_data >= LIST_LEN){		// 더 이상 저장할 공간이 없다면,
		puts("저장 한도를 넘어섰습니다.");
		return;
	}

	plist->arr[plist->num_of_data] = list_data;	// 데이터를 저장한다.
	(plist->num_of_data)++;						// 저장된 데이터의 수 증가
}// 데이터 저장

int list_first(struct array_list *plist, int *list_data)
{
	if(plist->num_of_data == 0)	// 저장된 데이터가 하나도 없다면,
		return false;

	(plist->cur_position) = 0;	// 참조위치를 초기화 한다. 즉, 첫 번째 데이터의 참조를 의미한다.
	*list_data = plist->arr[0];	// list_data가 가리키는 공간에 데이터를 저장한다.
	
	return true;
}// 첫 데이터 참조

int list_next(struct array_list *plist, int *list_data)
{
	if(plist->cur_position >= (plist->num_of_data)-1)	// 더 이상 참조할 데이터가 없다면,
		return false;

	(plist->cur_position)++;
	*list_data = plist->arr[plist->cur_position];		// 다음 데이터를 참조한다.

	return true;
}// 두 번째 이후 데이터 참조

int list_remove(struct array_list *plist)
{
	int rm_pos = plist->cur_position;	// 삭제할 데이터의 인덱스 값 참조
	int num = plist->num_of_data;
	int rm_data = plist->arr[rm_pos];	// 삭제할 데이터를 임시로 저장한다.

	int i;

	// 재조정한다. 즉, 삭제를 위한 데이터의 이동을 진행하는 반복문이다.
	for(i=rm_pos; i<num-1; i++)
		plist->arr[i] = plist->arr[i+1];

	(plist->num_of_data)--;		// 데이터의 수 감소
	(plist->cur_position)--;	// 참조위치를 하나 되돌린다. (이건 구현에 따라 다를 수 있음...?)

	return rm_data;				// 삭제된 데이터를 반환한다.
}// 참조한 데이터 삭제

int list_count(struct array_list *plist)
{
	return plist->num_of_data;
}// 저장한 데이터의 수 반환

void list_display_all(struct array_list *plist, int *list_data)
{
	// 현재 데이터의 개수를 출력한다.
	printf("현재 데이터의 수: %d \n", list_count(plist));

	// 첫번째 데이터로 참조 대상을 변경하고, 표준 출력으로 내보낸다.
	// 그리고 나머지 데이터들을 출력한다.
	// 이 함수가 수행된 후에는 현재 참조 대상이 맨 마지막 대상으로 바뀐다.
	if(list_first(plist, list_data){
		printf("%d ", *list_data);

		while(list_next(plist, list_data))
			printf("%d ", data);
	}

	printf("\n\n");
}

void list_display_cur_position(struct array_list *plist)
{	
	return plist->cur_position;
}
