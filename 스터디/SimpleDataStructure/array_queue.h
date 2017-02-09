#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

enum{
	false	=0,
	true	=1
};

#define QUE_LEN	100

struct queue{
	int front;	// 배열 기반이므로 인덱스를 나타낸다. 따라서 정수
	int rear;	// 배열 기반이므로 인덱스를 나타낸다. 따라서 정수
	int queue_arr[QUE_LEN];
}

void queue_init(struct queue *pq);
int queue_is_empty(struct queue *pq);

void enqueue(struct queue *pq, int q_data);
int dequeue(struct queue *pq);
void queue_peek(struct queue *pq);

#endif
