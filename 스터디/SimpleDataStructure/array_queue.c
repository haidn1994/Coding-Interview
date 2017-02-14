/*
	스택에 대해서 알고 있다면 큐를 이해하는 것도 어렵지 않다.

	스택이 데이터가 들어가고 나오는곳이 하나이고, 
	가장 먼저 들어간 데이터가 가장 마지막에 나오는 구조를 가지고 있다.
	이런 성질을 LIFO(Last In, First out)<후입선출>이라고 부른다.

	스택은 그 쓰임새가 다양한데, 특히 함수 구현에 있어서 없으면 안되는 지위를 가진다.

	큐는 스택과 비슷하지만 반대에 위치한 성질을 가지는 자료구조다.
	큐를 이해하는데 있어서 가장 쉬운 비유는 일상적으로 일어나는 '줄서기'이다.
	예를 들어서 내가 은행에 갔다고 해보자. 
	은행에서 업무를 처리하기 위해서는 번호표를 뽑고 자신의 차례가 될 때까지 기다려야 한다.
	이 때, 누가 먼저 업무를 처리할 수 있는지 결정하는 데 사용하는 기준은 
	'누가 먼저 줄을 섰는가?'가 되겠다.

	스택은 위에서도 말했듯이 먼저 들어간 데이터가 가장 늦게 나온다.
	이와 반대로, 큐는 먼저 들어간 데이터가 먼저 나온다.
	따라서 이런 큐의 성질을 FIFO(First In, First out)<선입선출>라고 부른다.

	그럼 큐가 반드시 가져야 할 연산은 무엇일까?

	enqueue	큐에 데이터를 넣는 연산
	dequeue	큐에서 데이터를 꺼내는 연산

	그림으로 표현하면 다음과 같다.

	뒤	Queue					앞
	-----------------------------
->	|	|	|	|	|	|	|	| ->
	-----------------------------
enqueue							  dequeue

	큐는 '뒤로 넣고 앞으로 빼는 자료구조'라고 기억하고 있어도 좋다.

	이제 간단한 배열 기반 큐를 구현해 보도록 한다.
	참고로, 대부분 이해하는 것과는 달리 스택을 살짝 변형하여 
	큐를 얻는것은 생각보다 어려울 것이다. 

	구현하기에 앞서서, 구체적인 설명을 하고 가겠다.

	큐를 구현하는데 거의 필수이라 생각할 수 있는 포인터 변수 두가지가 있는데 
	각각 앞과 뒤를 표현한다고 해서 front와 rear라고 부른다.
	이때 각각의 변수 rear와 front는 enqueue와 dequeue의 구현에 지대한 영향을 끼친다.

	먼저 enqueue 연산시 큐의 상황을 살펴보자. (단, front는 F이고, rear는 R이다.) 

	뒤	Queue					앞
	-----------------------------
->	|A	|	|	|	|	|	|	| ->
	-----------------------------
	F,R

ENQUEUE

	뒤	Queue					앞
	-----------------------------
->	|A	|B	|	|	|	|	|	| ->
	-----------------------------
	F	R

ENQUEUE

	뒤	Queue					앞
	-----------------------------
->	|A	|B	|C	|	|	|	|	| ->
	-----------------------------
	F	    R

	보는 바와 같이 크기가 8인 큐가 있을때 
	enqueue연산을 진행하면 R이 한칸씩 뒤로 밀려나 그 다음 칸을 가리키게 된다.

	같은 방식으로 만약 dequeue연산을 하게 된다면 F가 전에 가리키고 있던 데이터는 삭제되고, 
	F가 뒤로 한칸씩 밀려나게 될 것이다. 그런데 여기서 문제가 발생한다. 

	뒤	Queue					앞
	-----------------------------
->	|	|	|	|	|E	|F	|G	| ->
	-----------------------------
				     F		 R
DEQUEUE

	뒤	Queue					앞
	-----------------------------
->	|	|	|	|	|	|F	|G	| ->
	-----------------------------
						 F	 R
DEQUEUE

	뒤	Queue					앞
	-----------------------------
->	|	|	|	|	|	|	|G	| ->
	-----------------------------
							 F,R

	enqueue와 dequeue를 계속하다보면 언젠가는 이런 모양이 나오게되는데,
	이렇게 되면 앞에 공간은 충분한데 F,R이 앞으로 갈 수 있도록 구현되어 있지 않아서
	더 이상 쓰기 어려운 상황이 벌어진다.

	큐를 계속 쓰려면 어떤 방법을 취해야 할까?
	먼저 생각해 볼 수 있는 방법은,
	dequeue를 할 때마다 데이터를 앞쪽으로 이동하여 R을 앞뒤로 움직일수 있게 하는 방법이 있다.
	예를 들면 다음과 같다.

	뒤	Queue					앞
	-----------------------------
->	|A	|B	|C	|	|	|	|	| ->
	-----------------------------
	F	    R

DEQUEUE

	뒤	Queue					앞
	-----------------------------
->	|A	|B	|	|	|	|	|	| ->
	-----------------------------
	F	R

DEQUEUE

	뒤	Queue					앞
	-----------------------------
->	|A	|	|	|	|	|	|	| ->
	-----------------------------
	F,R

	하지만 이렇게 만들면 F가 의미가 사라진다.
	여기에 더해서 계속 데이터의 위치가 이동하게 된다면 큐의 성능이 좋지 않게 될 것이다.
	따라서, Dequeue방식을 유지하는 더 좋은 방법을 찾아야 한다.

	전산학에는 이에 대한 해결책으로 '원형 큐'를 제시한다.
	그럼 원형 큐의 개념에 대해서 알아보자.
	
	1. 우선 큐의 앞과 뒤를 잇는다. 이렇게 하면 큐의 모양이 원형으로 바뀐다.
	2. 그리고 적당한 지점을 잡아서 시작점으로 하고, F와 R은 한방향으로만 '회전'한다.
	3. 자세한 사항은 첨부한 그림을 참조하라.

	이제 한 방향으로 회전한다면 큐의 크기만큼 밀려났을때 시작점을 가리키게 된다.

	이제 쓸만한 큐를 만들수 있게 되었다.
	구현해보도록 한다.(참고로 원형큐를 구현할 것이다.)
 */
#include <stdio.h>
#include <stdlib.h>
#include "array_queue.h"

void queue_init(struct queue *pq)	// 큐가 텅 비어있다면 front와 rear는 동일 위치를 가리킨다.
{
	pq->front = 0;
	pq->rear = 0;
}

int queue_is_empty(struct queue *pq)
{
	if(pq->front == pq->rear)		// 큐가 텅 비었다면,
		return true;
	else
		return false;
}


int next_pos_idx(int pos)
{
	if(pos == QUE_LEN - 1)			// 인덱스가 최대치라면, 0을 반환한다. (이렇게 환형 큐를 구성한다.)
		return 0;
	else
		return pos+1;				
}

void enqueue(struct queue *pq, int q_data)
{
	if(next_pos_idx(pq->rear) == pq->front){	// 큐가 꽉 찼다면,
		printf("queue memory error!");
		exit(-1);
	}

	pq->rear= next_pos_idx(pq->rear);	// rear를 한 칸 이동
	pq->queue_arr[pq->rear] = data;		// rear가 가리키는 곳에 데이터를 저장한다.
}

int dequeue(struct queue *pq)
{
	if(queue_is_empty(pq)){
		printf("queue memory error!");
		exit(-1);
	}
	
	pq->front = next_pos_idx(pq->front);	// front를 한 칸 이동한다.
	return pq->queue_arr[pq->front];		// front가 가리키는 데이터를 반환한다.
}

int queue_peek(struct queue *pq)
{
	if(queue_is_empty(pq)){	
		printf("queue memory error!");
		exit(-1);
	}

	return pq->queue_arr[next_pos_idx(pq->front)];	// 큐의 front를 1 증가시킨 다음, 큐의 데이터를 참조한다.
}

