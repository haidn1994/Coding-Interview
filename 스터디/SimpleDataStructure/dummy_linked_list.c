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
// 해당 더미 노드는 tail이 없어서 앞쪽부터 노드의 삽입이 시작된다.
// 물론 tail이 있다면 뒤쪽에서 계속 노드가 추가될 것이다.
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

// 리스트의 장점은 삽입과 삭제가 굉장히 용이하다는 점이다.
// 반드시 이점 명심하도록!
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

// head는 dummy_node이므로, head->next노드부터 첫번째 데이터로 간주한다.
int list_first(struct linked_list *plist, int *pdata)
{
	if(plist->cur->next == NULL)
		return false;

	plist->before = plist-> head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return true;
}

// before 포인터와 cur 포인터를 한 칸씩 민다.
// 그리고 나서 바로 cur의 데이터를 얻어서 pdata에 집어 넣는다.
int list_next(struct linked_list *plist, int *pdata)
{
	if(plist->cur->next == NULL)
		return false;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;

	return true;
}

// rm_pos는 어떤 데이터를 지울 것인지 정하는 포인터이다.
// 여기는 cur를 대상으로 한다.

// rm_data는 그 데이터를 백업해 놓았다가 
// 나중에 지운 데이터를 반환한다.
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
