#include <stdio.h>
#include "ALgraph.h"

int main(void)
{
	struct al_graph graph;		// 그래프의 생성
	graph_init(&graph, 5);		// 그래프의 초기화


	add_edge(&graph, A, B);		// 정점 A와 B를 연결	
	add_edge(&graph, A, D);
	add_edge(&graph, B, C);
	add_edge(&graph, C, D);
	add_edge(&graph, D, E);
	add_edge(&graph, E, A);	

	show_graph_edge_info(&graph);	// 그래프의 간선 정보를 출력한다.
	graph_destroy(&graph);			// 그래프의 리소스를 해제(소멸)한다.

	return 0;
}
