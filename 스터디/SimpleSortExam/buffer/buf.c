
#include <stdio.h>

#define BUCKET_NUM	10

enum{
	false	= 0,
	true	= 1
};

struct node{
	int data;
	struct node *next;
};

struct list_queue{
	struct node *front;	// F를 포인터로 구현한다.
	struct node *rear;	// R을 포인터로 구현한다.
};

void queue_init(struct queue *pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int is_q_empty(struct queue *pq)
{
	if(pq->front == NULL)
		return true;
	else
		return false;
}

void enqueue(struct queue *pq, int data)
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
void radix_sort(int arr[], int num, int max_len)
{
	// max_len에는 정렬대상 중 가장 긴 데이터의 길이 정보가 전달
	struct queue buckets[BUCKET_NUM];
	int b_idx;
	int pos;
	int d_idx;
	int div_fac = 1;	// 피제수를 얻을 때 처음에는 곱셈에 대한 항등원이 필요하다.
	int radix;

	// 총 10개의 버킷 초기화
	for(b_idx = 0; b_idx < BUCKET_NUM; b_idx++)
		queue_init(&buckets[b_idx]);

	// 가장 긴 데이터의 길이만큼 반복
	for(pos = 0; pos < max_len; pos++){
		// 정렬 대상의 수 만큼 반복
		for(d_idx = 0; d_idx < num; d_idx++){
			// N번째 자리의 숫자를 추출한다.
			radix = (arr[d_idx]/div_fac) % 10;

			// 추출한 숫자를 근거로 버킷에 데이터를 저장한다.
			enqueue(&buckets[radix], arr[d_dix));
		}

		// 버킷 수만큼 반복한다.
		for(b_idx = 0, d_idx = 0; b_idx < BUCKET_NUM; b_idx++){
			// 버킷에 저장된 것 순서대로 다 꺼내서 다시 arr에 저장한다.
			while(queue_is_empty(&buckets[b_idx]))
				arr[d_idx++] = dequeue(&buckets[b_idx]);
		}

		// N번째 자리의 숫자 추출을 위한 피제수의 증가
		div_fac *= 10;
	}
}

int main(void)
{
	int count, i;
	int arr[10000000] = {0,};

	scanf("%d", &count);

	for(i = 0; i < count; i++)
		scanf("%d", &arr[i]);

	radix_sort(arr, count, 5);

	for(i = 0; i < cont; i++)
		printf("%d\n", arr[i]);
}
