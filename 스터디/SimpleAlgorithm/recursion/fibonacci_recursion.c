/*
	다음 예제는 어떠한 최적화 기법을 사용하지 않고,
	단순하게 재귀함수만 사용해서 피보나치 수열의 일반항을 얻는 예제이다.

	코드는 훨씬 간결하고, 수학의 함수와 유사하지만
	작은 문제로 쪼개고 해결해나가는 과정에서 엄청나게 많은 중복연산이 일어난다.
 */
#include <stdio.h>

int call_count = 0;

unsigned long long fibo(int n)
{
	call_count++;

	if(n == 1)
		return 0;
	else if(n == 2)
		return 1;
	else
		return fibo(n-1) + fibo(n-2);
}

int main(void)
{
	printf("피보나치 수열의 1항 부터 93항까지 구할 수 있지만 
			엄청나게 시간이 오래 걸리므로 15항 이하로 구하기 바란다.");

	printf("알고 싶은 항을 입력하시오:\n");
	scanf("%d", &n);
	printf("%llu \n", fibo(n));

	printf("함수 호출 회수: %d", call_count);

	return 0;
}
