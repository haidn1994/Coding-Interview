#include <stdio.h>
#include <stdlib.h>
#include "list_base_queue.h"

void queue_init(struct *pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int is_q_empty(struct *pq)
{
	if(pq->front == NULL)
		return true;
	else
		return false;
}

void enqueue(struct *pq, int data)
{
	struct node* new_node = 
		(struct node*)malloc(sizeof(struct node));
	new_node->next = NULL;
	new_node->data = data;

	if(is_q_empty(pq)){
		pq->front = new_node;
		pq->rear = new_node;
	} else {
		pq->rear->next = new_node;
		pq->rear = new_node;
	}
}

int dequeue(struct queue *pq)
{
	struct node *del_node;
	int del_data;

	if(is_q_empty(pq)){
		printf("queue memory error!");
		exit(-1);
	}

	del_node = pq->front;
	del_data = del_node->data;
	pq->front = pq->front->next;

	free(del_node);
	return del_data;
}

int q_peek(struct queue *pq)
{
	if(is_q_empty(pq)){
		printf("queue memory error!");
		exit(-1);
	}

	return pq->front->data;
}
