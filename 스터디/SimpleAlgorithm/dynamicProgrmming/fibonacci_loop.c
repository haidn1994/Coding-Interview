/*
	재귀 함수가 가장 느리고, 동적 프로그래밍이 그 다음이다.
	그럼 피보나치 수열을 가장 빠르게 구하는 방법은 뭘까?
	바로 반복문을 사용하는 방법이다.

	사실 재귀는 보통 반복문보다 더 느리고, 메모리도 더 많이 잡아먹는다.
	게다가 동적 계획법에 맞춰서 프로그램을 작성하더라도 루프가 더 빠를 가능성도 있다.

	예를 들어,루프로 구현된 fibo()는 지역 변수에 바로 전항의 값을 저장하고 있기 때문에 
	이를 활용해서 수열의 각 항을 구한다.
	오히려 동적 계획법을 적용한 fibo()는 함수 호출 비용때문에 시간이 더 많이 걸릴 수도 있다.

	그러나 캐시(cache)의 개념을 이해하는데 이만한 것도 드물고 
	재활용하고자 하는 데이터를 파일로 남겨놓으면, 프로세스가 종료되었다고 못쓰게 되는 것도 아니다.
	
	이제 반복문을 통한 피보나치 수열을 구하는 함수를 작성해 보자.
 */
#include <stdio.h>


unsigned long long fibo (int n) {
	unsigned long long temp1, temp2;
	unsigned long long result;
	int i;

	temp1 = 1;
	temp2 = 1;
	result = 1;

	for (i = 3; i <= n; i++) {
		result = temp1 + temp2;	// 현재 f(n-1) + f(n-2)를 통해서 f(n)을 구한다.
		temp1 = temp2;			// 구한 f(n)을 토대로 다음 f(n-1)과 f(n-2)f를 구한다.
		temp2 = result;
	}

	return result;
}


int main(void) {
	int n;

	printf("0항 부터 93항까지의 피보나치 수열을 
			루프를 적용하여 계산 하도록 설계되었다.\n");

	printf("알고 싶은 항을 입력하시오:\n");
	scanf("%d", &n);
	printf("%llu \n", fibo(n));

	return 0;
}
