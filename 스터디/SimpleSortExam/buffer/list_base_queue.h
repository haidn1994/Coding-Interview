#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

enum{
	false	= 0,
	true	= 1
};

struct node{
	int data;
	struct node *next;
}

struct list_queue{
	struct node *front;	// F를 포인터로 구현한다.
	struct node *rear;	// R을 포인터로 구현한다.
}

void queue_init(struct queue *pq);
int is_q_empty(struct queue *pq);

void enqueue(struct queue *pq, int data);
int dequeue(struct queue *pq);
int queue_peek(struct queue *pq);

#endif
