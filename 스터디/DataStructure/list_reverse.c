#include <stdio.h>


// 해당 프로그램은 더블 포인터의 이해를 돕기 위해서 list구조체를 사용하지 않는다.
struct node{
	int data;
	struct node *next;
}

void list_insert(struct node **phead, int pdata)
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = pdata;
	new_node->next = *head;
	*head = new_node;
}

// 여기는 출력만 하고 다른 쓰임새가 없기 때문에 
// 그냥 싱글 포인터로 넘겨도 상관 없다.
void list_print(struct node *phead)
{
	struct node *cur;
	cur = head;

	while(cur != NULL){
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

// 캐스팅 연산자, 함수 포인터, 변수 선언문에서 사용되는 모든 *을 제외하고
// 다른 곳에서 *이나 ->가 사용된다면 현재 스택 프레임 바깥에 접근하여 값을 바꾼다는 뜻으로 받아들일 수 있다.
// 여기에 더해 []를 인자로 받아 사용해도 현재 스택 프레임 바깥에 접근하는 것으로 받아들일 수 있다.
void list_reverse(struct node **head)
{
	// 배열과는 달리 임시변수가 1개 필요하다.
	struct node *cur, *pre, *tmp;

	pre = NULL;
	cur = *head;

	if(cur){
		while(cur->next){
			// tmp는 cur바로 앞쪽을 뜻함
			tmp = cur->next;
			// next포인터를 거꾸로 뒤집는다.
			cur->next = pre;
			// pre를 한칸 앞으로 민다.
			pre = cur;
			// tmp를 통해서 cur도 한칸 앞으로 민다.
		}	// NULL이 나올 때까지 계속 반복

		// 마지막 1개를 뒤집는다.
		cur->next = pre;
		// 현재 노드를 head로 변경한다.
		*head = cur;
	}
}

void list_reverse_between_MandN(struct node **phead,
								int m, int n)
{
	// 이번에는 변수가 4개 필요하다. 
	// 거기에 하나는 이중 포인터!

	struct node *cur = *head;
	struct node *pre = *head;
	struct node *start = NULL;
	struct node **end = head;
	int i;

	// 시작하는 부분을 찾는다. 즉, m번째 노드를 찾는다.
	for(i = 1; i < m; i++){
		end = (node**)&(cur->next);
		pre = cur;
		cur = cur->next;
	}
	// 찾아서 설정
	start = cur;

	// 뒤집기 m번째에서 n번째까지 뒤집는다.
	for(i = m; i <= n; i++){
		struct node next_node = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next_node;
	}
	// end와 start->next를 다시 설정한다.
	start->next = cur;
	*end = pre;
}


/*
	참고:
	
	http://blog.sbnet21.com/1752
	http://blog.sbnet21.com/1921
 */


