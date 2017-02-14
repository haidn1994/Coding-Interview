/*
   저번 시간까지 우리는 배열을 기반으로 한 리스트를 작성했는데,
   이 방식은 속도는 빠르지만 배열 길이를 바꿀 수 없어서 유연성이 떨어진다.
   (길이를 변경하고 싶다면 기존 배열의 데이터를 보다 큰 배열을 만들어 옮겨야 한다.)

   따라서 보다 유연한 방식인 
   힙(heap)에 동적 할당(dynamic allocation) 하는 방식으로 리스트를 구현하는 방법을 살펴보겠다.
   
   이 코드를 이해하는 데 있어서 선행 조건은 동적 할당의 이해와,
   malloc() free()의 이해가 되겠다.

   동적 할당된 변수의 특징은 다음과 같다.
   "함수가 매번 호출될 때마다 새롭게 할당되고, 또 함수를 빠져나가도 유지가 되는 유형의 변수
    정적 할당과 가장 큰 차이점은 동적 메모리의 경우, 그 메모리의 해제시점을 내가 원할때 정할 수 있다."

   malloc()과 free()의 함수 원형은 다음과 같다.

   #include <stdlib.h> <- 여기에 정의되어 있다.

   void *malloc(size_t size);	// 힙 영역으로의 메모리 공간 할당
   void free(void *ptr);		// 힙 영역에 할당된 메모리 공간을 해제한다.

   malloc()은 할당 받고 싶은 힙 메모리의 크기(size_t size)를 인자로 받아서,
   그 메모리의 시작 주소(void *)를 반환한다.
   참고로, 사실 size_t는 unsigned int를 typedef로 숨긴 형태로 주로 메모리의 크기, 
   구체적으로 구조체의 크기, 배열의 크기등을 나타낼 때 사용한다.
   sizeof()연산자가 반환하는 자료형이 바로 size_t이다.

   free()는 malloc()을 통해 할당받은 메모리의 주소를 인자로 받아서,
   해당 메모리를 회수한다.

   여기에 더해서, 왜 void*를 반환형이나 인자로 사용할까? 
   그 이유는 해당 함수, 알고리즘을 자료형에 구애 받지 않고 사용하겠다는 뜻으로 이해 할 수 있다.
   즉, C에서 제네릭 프로그래밍(generic programming)을 사용하는 방법으로 이해 하면 되겠다.

   다만 C에서는 형변환이 묵시적으로 이루어지는 경우가 많고, 타입 에러를 찾기 어려운 경우가 상당히 많아서
   이 점을 유의하여 코드를 작성해야 한다.

   이 코드는 간단한 예시로, 따로 함수를 작성하지 않고 연결리스트의 특징을 보여준다.
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}

int main (void)
{
	struct node *head = NULL;
	struct node *tail = NULL;
	struct node *cur  = NULL;
	
	struct node *new_node = NULL;

	int user_input;

	// 데이터를 입력 받는 과정
	for(;;){
		printf("자연수 입력: ");
		scanf("%d", &user_input);

		if(user_input < 1)
			break;

		// 노드의 추가과정

		// 노드의 동적 할당(포인터 타입만 된다.)
		new_node = (struct node*)malloc(sizeof(struct node));

		// 데이터는 채워주고, 다음 포인터는 NULL로 채워준다.
		new_node->data = user_input;
		new_node->next = NULL;

		// 헤드 노드 포인터가 NULL이면 newNode는 헤드에 할당된다.
		if(head == NULL)
			head = new_node;
		else
			tail->next = new_node;	// 이건 tail 구조체의 멤버 포인터(다음 노드를 가리키도록 설계되어 있다.)

		tail = new_node;			// 이건 tail 구조체 포인터
	}
	printf("\n");

	// 입력 받은 데이터의 출력과정
	printf("입력 받은 데이터의 전체출력! \n");
	if(head == NULL){
		printf("저장된 자연수가 존재하지 않습니다. \n");
	} else {
		cur = head;
		printf("%d ", cur->data);	// 첫 번째 데이터 출력

		while(cur->next != NULL){
			cur = cur->next;		// 구조체 멤버의 포인터로 다음 노드에 접근
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	// 메모리의 해제과정
	if(head == NULL){
		return 0;					// 해제할 노드가 존재하지 않는다.
	} else {
		// 헤드부터 삭제를 시작해야 한다.
		struct node *del_node = head;
		struct node *del_next_node = head->next;

		// 첫번째 노드부터 삭제한다.
		printf("%d을(를) 삭제합니다. \n", head->data);
		free(del_node);

		// 두번째 이후의 노드를 삭제한다.
		while(del_next_node != NULL){
			// 아직 멤버 포인터는 유실되지 않았다.
			del_node = del_next_node;
			del_next_node = del_next_node->next;

			printf("%d을(를) 삭제합니다. \n"), del_node->data);
			free(del_node);
		}
	}

	return 0;
}

/*

   자세히 봤다면 알 수 있겠지만 동적 메모리를 사용할 때,
   일반적인 구조체 타입이나 원시 자료형을 사용하지 않고 포인터 타입을 사용한다.

   즉, 동적 메모리를 잘 사용하려면 포인터 타입을 잘 사용해야 한다.
   또한 이에 대한 이해는 자바의 레퍼런스 타입을 보다 심도깊게 이해하고 사용하는데 큰 도움이 된다.

 */
