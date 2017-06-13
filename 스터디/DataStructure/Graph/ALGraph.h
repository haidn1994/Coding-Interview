#ifndef __AL_GRPAH__
#define __AL_GRAPH__

#include "DLinkedList.h"

// 정점의 이름을 상수화
enum {A, B, C, D, E, F, G, H, I, J};

struct al_graph{
	int numV;	// 정점의 수
	int numE;	// 간선의 수
	struct linked_list adj_list;	// 간선의 정보
}

// 그래프의 초기화
void init_graph(struct al_graph *pg, int nv);

// 그래프의 리소스 해제
void destroy_graph(struct al_graph *pg);

// 간선의 추가
void add_edge(struct al_graph *pg, int fromV, int toV);

// 간선의 정보 출력
void show_graph_edge_info(struct al_graph *pg);
