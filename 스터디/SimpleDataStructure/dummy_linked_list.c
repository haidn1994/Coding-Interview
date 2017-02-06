#include <stdio.h>
#include <stdlib.h>
#include "dummy_linked_list.h"

void list_init(struct linked_list *plist)
{
	// 처음 리스트를 동적 할당할때 사용하는 코드
	plist->head = (struct node*)malloc(sizeof(struct node));
	// 다음 멤버를 가리키는 head node의 포인터는 당연히 NULL을 가리킬 것이다.
	plist->head->next = NULL;
	// 비교 전략을 정하는 함수 포인터도 여기서 정한다.
	plist->comp = NULL;
	// head는 dummy node이다. 따라서 num_of_data는 0으로 초기화 된다.
	plist->num_of_data = 0;
}

// list_insert내부에 숨겨져서 호출되는 함수
// 리스트가 처음 삽입될 때 사용되는 함수이기도 하다.
void first_insert(struct linked_list *plist, int data)
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node*));
	new_node->data = data;

	new_node->next = plist->head->next;
	plist->head->next = new_node;

	(plist->num_of_data)++;
}

// 데이터를 넣기는 넣는데 정렬함수를 실행시키면서 어디에 들어갈지
// 정하는 방식을 사용하는 함수라고 할 수 있다.
void sort_insert(struct linked_list *plist, int data)
{
	// 작성중
}

// 내부적으로 first_insert와 sort_insert를 호출하는 방식을 취한다.
void list_insert(struct linked_list *plist, int data)
{
	if(plist->comp == NULL)
		first_insert(plist, data);
	else
		sort_insert(plist, data);
}

int list_first(struct linked_list *plist, int *pdata)
{
	if(plist->cur->next == NULL)
		return false;

	plist->before = plist-> head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return true;
}

int list_next(struct linked_list *plist, int *pdata)
{
	if(plist->cur->next == NULL)
		return false;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;

	return true;
}

int list_remove(struct linked_list *plist)
{
	struct node *rm_pos = plist->cur;
	int rm_data = rm_pos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rm_post);
	(plist->num_of_data)--;
	return rm_data;
}

int list_count(struct linked_list *plist)
{
	return plist->num_of_data;
}

void set_sort_rule(struct linked_list *plist, int (*comp)(int data1, int data2))
{
	// 작성중
}
