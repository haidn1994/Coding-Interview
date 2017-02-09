#include <stdio.h>
#include "array_queue.h"


int main(void)
{
	// queue의 생성 및 초기화
	struct queue q;
	queue_init(&q);

	// 데이터 넣기
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 5);

	// 데이터 꺼내기
	while(!is_queue_empty(&q))
		printf("%d ", dequeue(&q));

	exit(1);
}
