/*
	현재 함수 스택 프레임 바깥에 영향을 주는지 아닌지를 판단하려면
	타입 선언, 캐스팅이 아닌 곳에 *이 붙어 있거나 ->이 붙어 있으면서
	=(할당 연산자)가 있다면 함수의 스택 프레임 바깥에 영향을 주는 것으로 간주 할 수 있다.

	물론 =의 좌변에 포인터로 받아온 인자(argument)가 있어야 겠지만...
 */
#include <stdio.h>
#include <stdlib.h>

enum{
	false	= 0,
	true	= 1
};

struct node{
	int data;
	struct node *next;
};

struct linked_list{
	struct node *head;
	struct node *cur;
	struct node *tail;
	int num_of_data;
};

// struct linked_list의 동적 할당은 따로 해줘야 한다.
// 이건 그 멤버변수들의 초기화를 담당하는 함수일 뿐이다.
void init_linked_list(struct linked_list *plist)
{
	plist->head = NULL;
	plist->tail = NULL;
	plist-> num_of_data = 0;
}

// 실제 노드의 삽입은 tail에서 일어난다.
// 하지만 head가 NULL일때는 새로운 노드는 head에 삽입된다.
void insert_node(struct linked_list *plist, int data)
{
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;

	if(plist->head == NULL){
		plist->head = new_node;
		plist->tail = new_node;	
	} else {
		plist->tail->next = new_node;
		plist->tail = new_node;
	}

	(plist->num_of_data)++;
}

// 참고로 pos를 지정하는 방법은 head는 0이고 tail은 num_of_data-1을 가리킨다.
// 다만 알다시피 연결 리스트는 검색에 O(n)의 성능을 보인다.
// 삽입과 삭제 그 자체로는 O(1)의 시간 복잡도를 보인다.
void delete_node(struct linked_list *plist, int pos)
{
	struct node *del_node;
	struct node *temp;
	int del_data, i;
	point_first_node(plist);

	// temp 찾아서 대입
	for(i = 0; i < pos - 1; i++){
		point_next_node(plist);
	}
	temp = plist->cur;

	// pos찾아서 대입
	point_next_node(plist);
	del_node = plist->cur;

	// 지우기전에 cur의 포인터값이 
	// 엉뚱한 메모리를 가리키지 않도록 조치한다.
	// 노드 연결 정보도 수정해 준다.
	temp->next = plist->cur->next;
	plist->cur = temp;

	// 해제, 리스트 노드의 갯수도 감소시킨다.
	free(del_node);
	(plist->num_of_data)--;
}

// plist->cur가 head를 가리키게 된다.
void point_first_node(struct linked_list *plist)
{
	if(is_linked_list_empty(plist)){
		printf("list is empty");
		return;
	}

	plist->cur = plist->head;
}

void point_next_node(struct linked_list *plist)
{
	plist->cur = plist->cur->next;
}

// 리스트의 노드가 하나라도 있으면 true
// 하나도 없으면 false
int is_linked_list_empty(struct linked_list *plist)
{
	if(plist->head == NULL)
		return true;
	else
		return false;
}

// head부터 시작해서 차례로 하나씩 print한다. 
void print_linked_list(struct linked_list *plist)
{
	point_first_node(plist);

	while(plist->cur->next != NULL){
		printf("%d -> ", plist->cur->data);
		plist->cur = plist->cur->next;
	}

	printf("%d -> ", plist->cur->data);
	printf("NULL\n");
}

int get_num_of_data(struct linked_list *plist)
{
	return plist->num_of_data;
}

int main(void)
{
	int menu=0;
	int data=0;
	int idx=0;
	// 자바의 레퍼런스처럼 활용해보려고 했다.
	struct linked_list *plist;

	// 두개를 합치면 생성자(constructor)로 간주할수 있을 것 같다.
	plist = (struct linked_list*)malloc(sizeof(struct linked_list));
	init_linked_list(plist);

	while(menu <= 4)
	{	
		printf("메뉴 선택 1.노드 삽입    2.노드 삭제    3.리스트 보기 4.노드의 총 갯수 보기    5.종료\n");
		scanf("%d", &menu);

		switch (menu)
		{
			case 1:
				printf("리스트에 삽입할 값을 입력하세요");
				scanf("%d",&data);
				insert_node(plist, data);
				break;
			case 2:
				printf("삭제할 노드의 인덱스를 입력하세요");
				scanf("%d",&idx);
				delete_node(plist, idx);
				break;
			case 3:
				print_linked_list(plist);
				break;
			case 4:
				printf("총 노드의 갯수는 %d개 입니다.\n", get_num_of_data(plist));
				break;
			case 5:
				free(plist);
				exit(1);
				break;
		default :
				printf("잘못된 메뉴 입력");
				break;

		}
	}
}
















