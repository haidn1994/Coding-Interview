/*
   처음에 dummy node를 만들면 연결 리스트를 관리하는데 있어서
   메모리를 노드 1개 만큼 낭비하게 되지만, 일관성을 얻을 수 있다. 

   이번 시간에는 더미 노드를 기준으로 하여 연결 리스트를 만들어 보도록 하겠다.

   참고: 공개 API는 주로 헤더로 작성하게 되고,
   헤더 파일에 보이지 않더라도 .c파일에 내부 중첩된 형태로 나타나기도 한다.
 */

#ifndef __DUMMY_LINKED_LIST_H__
#define __DUMMY_LINKED_LIST_H__

enum{
	false	= 0,
	true	= 1
};

// 역시 단순한 예제이기 때문에 typedef는 되도록 피한다.

// 노드의 정의는 그대로 이어진다.
struct node{
	int data;
	struct node *next;
}

// 연결 리스트를 새롭게 정의한다.
struct linked_list{
	// 연결 리스트의 시작점
	struct node *head;
	// 해당 연결 리스트가 현재 참조하고 있는 노드
	struct node *cur;
	// 작성중
	struct node *before;

	// 해당 연결 리스트의 총 노드의 갯수
	int num_of_data;
	// 크고 작음을 판단할 함수를 참조하는 함수 포인터
	int (*comp)(int data1, int data2);
}

void list_init(struct linked_list *plist);
void list_insert(struct linked_list *plist, int data);

int list_first(struct linked_list *plist, int *pdata);
int list_next(struct linked_list *plist, int *pdata);

int list_remove(struct linked_list *plist);
int list_count(struct linked_list *plist);

void set_sort_role(struct linked_list *plistm, int (*comp)(int data1, int data2));

#endif
