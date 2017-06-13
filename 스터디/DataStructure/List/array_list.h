#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

// true와 false도 매크로 정의 보다는 enum이 좀 더 좋아 보인다.
enum{
		false	= 0,
		true	= 1
};

/*
	원칙적으로는 배열의 길이가 모자라는 상황이 생길때 마다 
	크기를 << 1 씩 늘리고, 그전에 있던 자료를 옮겨서 복사해줘야 하지만,
	일단은 배열처럼 고정된 크기를 사용하도록 한다.

	참고로 배열기반으로 크기를 재할당하는데 걸리는 시간은 O(n)이다.
 */

#define LIST_LEN	100
// 간단한 예제니까 굳이 typedef로 데이터 자료형을 숨길 이유는 없다.


struct array_list{		// 배열기반 리스트를 정의한 구조체
	int arr[LIST_LEN];	// 리스트의 저장소인 배열
	int num_of_data;	// 저장된 데이터의 수
	int cur_position;	// 데이터 참조위치를 기록
};

// 함수의 원형들

void list_init(struct array_list *plist);					// 리스트 초기화
void list_insert(struct array_list *plist, int list_data);	// 데이터 저장

int list_first(struct array_list *plist, int *list_data);	// 첫 데이터 참조
int list_next(struct array_list *plist, int *list_data);	// 두 번째 이후 데이터 참조

int list_remove(struct array_list *plist);					// 참조한 데이터 삭제
int list_count(struct array_list *plist);					// 저장한 데이터의 수 반환

void list_display_all(struct array_list *plist, int *list_data); // 노드의 모든 데이터를 출력한다.
int list_display_cur_position(struct array_list *plist);		 // 현재 참조중인 인덱스를 반환 

// 참고1: 리눅스 커널의 리스트 자료형은 NODE나 data란 용어 대신 list_head라는 용어를 사용한다.

#endif
// 참고2: 헤더파일을 사용해서 구조적으로 프로그램을 작성하려면,
// 선행처리기(전처리기)와 매크로에 대한 공부도 필요하다.


