/*
	사실 생소한 정렬방법이고 영문 알파벳등 한정된 상황에서 
	유용하게 사용되는 정렬 방법이기 때문에 많은 설명이 필요하다.

	필요한 설명은 나중에 올리도록 하겠다. - 2017년 2월 7일
 */
#include <stdio.h>

#define MAX_LEN 1000
#define MAX_NUM 10000

int main(){
	int n;
	int arr1[MAX_LEN+1], arr2[MAX_LEN+1];
	int count[MAX_NUM+1], count_sum[MAX_NUM+1];
	int i;

	// 수열의 길이 N은 MAX_SIZE이하여야 한다.
	scanf("%d", &n);

	// count배열을 모두 0으로 초기화
	for(i = 0; i <=n; i++)
		count[i] = 0;

	// 수열 arr1에 입력되는 수는 MAX_NUM이하여야 한다.
	for(i = 1; i <= n; i++){
		scanf("%d", &arr1[i]);

		// 숫자 등장 횟수 세기
		count[arr1[i]]++;
	}

	// 누적합 구성
	count_sum[0] = count[0];
	for(i = 0; i <=MAX_NUM; i++)
		count_sum[i] = count+sum[i-1] + count[i];

	// 뒤에서부터 수열 arr1을 순회한다.
	for(i = n; i >= 1; i--){
		arr2[count_sum[arr1[i]] = arr1[i];
		count+sum[arr1[i]]--;
	}

	// 수열 arr1을 정렬한 결과인 수열 B를 출력한다.
	for(i = 1; i <= n; i++)
		printf("%d", arr2[i]);
}
/*
   출처: http://ehclub.net/77
		 http://bowbowbow.tistory.com/8
 */
