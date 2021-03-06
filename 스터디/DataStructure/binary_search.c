/*
	이 프로그램 역시 배열을 기반으로 만들었다.
	또한 설명도 배열을 기반으로 구현했을 경우로 한정하여 설명한다.

    이진 탐색은 한가지 제약 조건이 있지만 순차 탐색에 비해서 굉장히 빠른 속도를 자랑한다.
	이제 제약 조건과 왜 속도가 빠른지, 얼마나 빠른지에 대해서 알아보자.

	제약 조건?:
		
	이진 탐색을 하는데 있어서 제약조건은 반드시 데이터가 정렬되어 있어야 한다는 점이다.
	왜냐하면, 대상을 찾을 때 항상 중앙에 있는 데이터에 접근하고 대상이 아니라면,
	프로세스는 다음과 같이 판단하여 다음 행동을 결정한다.

	(데이터가 정수일 때를 기준으로 설명한다.)
	예를 들어, 데이터가 배열(arr)으로 구성되어 있고 인덱스가 0부터 n-1까지 있다고 하자
	데이터는 오름차순으로 정렬되어 있다.

	찾고자 하는 대상이 얻은 수(처음 얻은 수는 arr[n-1/2])보다 크다면 
	찾는 범위를 n-1/2 ~ n-1까지 줄인다. 
	그리고 다시 접근할때는 이 범위의 중앙에 있는 데이터에 접근한다.

	반대로 찾고자 하는 대상이 얻은 수보다 크다면 
	찾는 범위를 0 ~ n-1/2까지 줄인다. 
	역시 다시 접근할때는 이 범위의 중앙에 있는 데이터에 접근한다.

	여기서 알 수 있는 점은 이진 검색을 수행할 때 
	찾고자 하는 대상보다 얻은 수보다 크면, 
	얻은 수의 인덱스보다 더 큰 인덱스들을 다음 검색 범위로 삼고,
	반대로 찾고자 하는 대상이 얻은 수보다 작으면,
	앋은 수의 인덱스보다 더 작은 인덱스들을 다음 검색 범위로 삼는다.

	오름차순을 기준으로 이 검색조건에 따라 검색이 문제없이 수행되려면 
	작은 인덱스로 접근할 수 있는 수들보다 큰 인덱스로 접근 가능한 수가 최소한 같거나, 커야한다. 
	반대로 큰 인덱스로 접근가능한 수들은, 작은 인덱스로 접근 가능한 수보다 최소한 같거나, 작아야 한다.

	빠른 이유?:

	전체 원소의 개수가 n개라고 했을 때,
	순차 탐색은 검색을 한번 수행할때 마다 검색해야 하는 원소의 개수가 1개 밖에 줄어들지 않는다.

	하지만 이진 탐색은 검색을 한번 수행할 때마다 검색해야 하는 원소의 개수가 절반씩 감소한다.
	따라서 얼핏 생각해봐도 순차탐색보다는 훨씬 빠르다는 사실을 알 수 있다. 

	얼마나 빠른가?:

	데이터의 갯수가 n개 일때, 최악의 경우(worst case)를 생각해보면
	
	* n이 1이 되기까지 2로 나눈 회수 k회, 따라서 비교연산 k회 진행
	* 데이터가 1개 남았을 때, 마지막으로 비교연산 1회 진행

	따라서 최악의 경우 시간 복잡도는 k + 1이 된다.
	이제 k를 정확하게 구해보자. 위에서 언급한대로 해보면 n과 k에 관한 식을 다음과 같이 세울 수 있다.

	n * (1/2)^k = 1
	(2로 k번 나누는 것은 1/2을 k번 곱하는 것과 같다.)
	이 식을 n에 관해서 정리하면, 

	n * (1/2)^k = 1 -> n * 2^(-k) = 1 -> n = 2^k
	우리가 궁극적으로 알고 싶은 것은 k에 관한 식이다.
	이 경우, 밑이 2인 로그를 취하면 k에 관한 식이 나올것이다.

	n = 2^k -> log(2)n = log(2)2^k -> log(2)n = k*log(2)2 -> log(2)n = k
	따라서 k는 log(2)n이라는 결론을 얻을 수 있다.

	그리고 이진 검색의 시간 복잡도를 T(n)이라고 할 때, 얻을 수 있는 식은 다음과 같다.
	T(n) = log(2)n + 1 

	이제 이진 검색을 구현하는 간단한 프로그램을 작성해 보겠다.
 */
#include <stdio.h>
#include <stdlib.h>

int binary_search(int ar[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;

	while(first <= last)
	{
		mid = (first+last)/2;	// 탐색 대상의 중앙을 찾는다.

		if(target == ar[mid]){	// 중앙에 저장된 것이 타겟이라면,
			return mid;			// 탐색 완료!
		} else {

			if(target < ar[mid])
				last = mid - 1;	// 왜 -1를 했을까?
			else
				first = mid + 1;// 왜 +1을 했을까?
		}

	}

	return -1;	// 찾지 못했음을 의미하는 값 -1반환
}


// 참고로 이렇게 만들어도 좋다.	
// 그런데 이렇게 만들면 연산자 우선순위를 고려해 줘야 한다.
int pretty_bsearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;

	while(first <= last)
	{
		// debuging용
		printf("first:%d  last:%d\n", first, last);
		// 그런데 이 중앙값을 찾는 로직도 최적화 여지가 있다.
		// 또한 경우에 따라 정수 오버플로우 에러가 발생할 수 있는데,
		// 이 부분에 대해서 다룬 웹 페이지와 부록(맨 아래)이 있다. 참고하도록 하라.

		// 다 읽어 보았는가?
		// 배열을 기반으로 만든 이진 탐색의 경우 first <= last인 signed int이며, 
		// 탐색 실패시 대표적인 last와 first의 값은 다음과 같다.


		// 맨 앞쪽의 원소보다 찾고자 하는 수가 작아서 못찾음 first = 0, last = -1
		// 맨 뒤쪽의 원소보다 찾고자 하는 수가 커서 못찾음 first = len+1, last = len

		// TODO 탐색실패 하지 않는다면,왜 last가 0미만이 될 수 없는지 증명해 볼 것!


		/*
		 	음수 아닌 정수 끼리의 곱셈(나눗셈도 마찬가지다.)은 언제나 음수 아닌 정수에 대해 닫혀 있다.

			또한 대상이 양수 아니면 0이라 했을 때, 
			/를 이용하면 바닥 평균(음수 아닌 정수)을 반환하고 
			천장 평균을 반환하더라도 언제나 음수 아닌 정수를 반환한다.
		
			따라서 배열의 인덱스 범위는 음수 아닌 정수이므로, 
			탐색에 실패하지 않는다면 언제나 음수 아닌 정수를 반환한다.

			탈출 조건을 만족한다면, 어차피 mid의 값은 의미가 없어진다.
			따라서 first = 0 last = -1인 경우가 유일하게 음수가 등장하는 경우이지만
			mid 에 대입하기 전에 while에서 탈출한다.

			결론적으로 언제나 배열 기반 이진 탐색 수행시, 
			first와 last는 언제나 음수 아닌 정수로 간주 할 수 있다.

			이 경우에는 (x + y) >> 1로 계산하는 것이 최선이다.
		 */
		
		// mid = (first+last)/2;
		mid = (first+last) >> 1;

		if(target == ar[mid])
			return mid;
		else{
		    target < ar[mid] ? (last = mid - 1) : (first = mid + 1);
			printf("대입 후-> first:%d  last:%d\n", first, last);
		}
	}

	return -1;
}


/*
 	+1과 -1을 하는 이유에 대해서 알아보자.

	검색을 수행할 때마다 값을 하나 더하거나 빼서 그 결과를 last와 first에 저장하지 않으면,
	mid에 저장된 인덱스의 배열요소도 새로운 탐색의 범위에 포함이 된다.
	하지만 이는 낭비다. ar[mid]에 탐색 대상이 저장되어 있는지 검사가 이미 끝난 상태이기 때문이다.

	그리고 -1과 +1을 하지 않으면 프로세스가 무한루프에 빠져 벗어나지 못하게 된다.

	이는 탐색 대상이 배열에 존재하지 않을 경우,
	first에 저장된 값이 last보다 커져서 반복문을 탈출할 수 있어야 하는데
	-1, +1이 없으면 결코 first에 저장된 값은 last보다 커질 수 없다.
	따라서 프로세스가 무한루프에 빠지게 되는 것이다.
 */
void print_idx(int idx)
{
	if(idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);
}


int main (void)
{
	int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};	// 데이터는 정렬되어 있다.
	int idx;	// 타겟의 인덱스

	int menu = 0;
	int user_input = 0;

	int i;

	for(;;){
		
		printf("메뉴: 1.이진 검색하기 2.배열 원소 보기 3.종료 4.예쁜 이진탐색\n");
		scanf("%d", &menu);

		switch(menu){
			case 1:
				printf("찾을 정수를 입력하세요\n");
				scanf("%d", &user_input);
				
				idx = binary_search(arr, sizeof(arr)/sizeof(int), user_input);
				print_idx(idx);
				break;
			case 2:
				printf("프로세스 배열:");
				for(i = 0; i < sizeof(arr)/sizeof(int); i++)
					printf("%d ", arr[i]);
				printf("\n");
				break;
			case 3:
				printf("프로세스를 종료합니다.\n");
				goto exit;
			case 4:
				printf("찾을 정수를 입력하세요\n");
				scanf("%d", &user_input);
				
				idx = pretty_bsearch(arr, sizeof(arr)/sizeof(int), user_input);
				print_idx(idx);
				break;
			// 여기에도 default대신에 비트 연산자로 정수 경계 연산을 해주면 좋을 것이다.
			// 공부해 볼 것!
			default:
				printf("잘못된 입력입니다.\n");
				break;
		}
	}

exit:
	exit(1); 
}

/*

    부록: C와 C++에서 두 수의 평균을 정확하게 구해 봅시다.
	(주의!: 최종 연산 결과가 overflow조건을 만족한다면, 아래에 소개된 방법은 전부 의미 없다.)

	정수 x와 y가 있다고 하자, 두 수의 산술 평균을 구하기 위해서는 다음과 같이 계산할 수 있다.

	-> (x+y)/2

	사람이 손으로 계산할 때는 별 문제가 없지만,
	컴퓨터로 계산할 때는 x+y가 overflow가 발생할 만큼 충분히 크다면, 이는 문제가 된다.
	따라서 넘친 비트를 만회하기 위해서 x와 y중 더 작은 수를 더하면 된다. (서로 같다면 아무거나)
	여기서는 x가 y보다 작거나 같다고 가정하겠다.

	-> x + ((y-x)/2)

	하지만 이 방법도 0 <= x <= y를 언제나 만족한다면 상관없지만...
	아니라면? 예를 들어 다음과 같은 상황에서는 오류를 만든다.

	y = 0, x = 1이 되면 (-1)/2 이 계산되면서 문제가 되고,
	y = 0, x = INT_MIN이 되면 overflow에러가 발생한다.

	그러면 모든 정수에 대해 overflow오류 없는 방법은 없는것일까?
	있다. 단, 바닥 평균을 구하는 식 따로, 천장 평균을 구하는 식 따로 마련되어 있다.

	다음은 바닥(floor ->  참고문헌을 참조하라) 평균을 overflow에러 없이 구하는 공식이다.

	-> (x & y) + ((x ^ y) >> 1)

	그리고 천장(ceiling) 평균을 에러없이 구하는 공식이다.

	-> (x | y) - ((x ^ y) >> 1)

	절사 평균(truncated average)을 구하는 공식도 있는데, 이는 일단 넘어가도록 한다.

	그리고 앞서 말했듯이 특정한 조건을 만족한다면, 비교적 간단한 식으로도 계산하는데 무리가 없다.

	1. x와 y가 signed int이고 음수가 아님을 보장할 수 있다면, 다음과 같이 계산하면 된다.

	-> (x + y) >> 1

	합에서 overflow가 발생할 수 있지만, 넘침 비트가 합을 담은 레지스터 안에 남아 있으므로,
	부호 없는 자리이동에 의해 넘침 비트가 적절한 자리로 이동하고 부홉트에는 0이 채워진다.

	2.  x와 y가 unsigned int이면서, x <= y를 만족하거나
		x와 y가 signed int이면서, x <= y를 만족한다면, 다음과 같이 구할 수 있다.

	-> x + ((y - x) >> 1)

	참고로 이는 바닥 평균이다.
	여기에 더해, >>를 사용할 경우 미세하지만 /에 비해 성능 이점을 누릴수 있다.

    참고문헌
   		
    서적

    * 해커의 기쁨 - 헨리 워렌 22p ~ 23p

    웹페이지


	* https://kldp.org/node/122637
	* https://research.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
	* https://en.wikipedia.org/wiki/Binary_search_algorithm
	* https://en.wikipedia.org/wiki/Floor_and_ceiling_functions
	* https://ko.wikipedia.org/wiki/%EB%B0%94%EB%8B%A5_%ED%95%A8%EC%88%98%EC%99%80_%EC%B2%9C%EC%9E%A5_%ED%95%A8%EC%88%98
*/


	
