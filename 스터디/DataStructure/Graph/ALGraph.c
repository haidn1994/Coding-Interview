#include <stdio.h>
#include <stlib.h>
#include "ALGraph.h"
#include "DLinkedList.c"

int who_is_precede(int data1, int data2);

// 그래프의 초기화
void graph_init(struct al_graph *pg, int nv)
{
	int i;

	// 정점의 수에 해당하는 길이의 리스트 배열을 생성한다.
	pg->adj_list = malloc(sizeof(struct linked_list) * nv);	// 간선정보를 저장할 리스트를 생성한다.

	pg->numV = nv;	// 정점의 수는 nv에 저장딘 값으로 결정한다.
	pg->numE = 0;	// 초기의 간선 수는 0개

	// 정점의 수만큼 생성된 리스트들을 초기화 한다.
	for(i = 0; i < nv; i++){
		init_linked_list(&(pg->adj_list[i]));
		set_sort_rule(&(pg->adj_list[i]), who_is_precede);
	}
}

// 그래프 리소스의 해제
void destory_graph(struct al_graph *pg)
{
	if(pg->adj_list != NULL)
		free(pg->adj_list);		// 동적으로 할단된 연결 리스트의 소멸
}

// fromV, toV 연결하는 간선 추가
void add_edge(struct al_graph *pg, int numV, int numE)
{
	// 정점 fromV의 연결 리스트에 정점 toV의 정보를 추가한다.
	list_insert(&(pg->adj_list[fromV]), toV);

	// 정점 toV의 연결 리스트에 정점 fromV의 정보 추가
	list_insert(&(pg->adj_list[toV]), fromV);
	pg->numE += 1;
}

// 간선의 정보 출력
void show_graph_edge_info(struct al_graph *pg)
{
	int i;
	int vx;

	for(i = 0; i < pg->numV; i++){
		printf("%c와 연결된 정점: ", i + 65);
		
		if(list_first(&(pg->adj_list[i]), &vx)){
			printf("%c ", vs + 65);

			while(list_next(&(pg->adj_list[i]), &vx)
				printf("%c ", vx + 65);		
		}
		printf("\n");
	}
}

int who_is_precede(int data1, int data2)
{
	return (data1 < data2) ? 0 : 1;
}


































