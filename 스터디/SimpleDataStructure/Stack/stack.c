/*
	이 스택은 배열 기반으로 만들어졌습니다.
	출처:http://itng.tistory.com/114

	2/1	이 프로그램은 오류가 있다.

	2/2 오류잡음 -> top의 초기값을 -1로 바꾸고 
	empty의 기준도 -1로 바꾸었다.
	그리고 display()의 조건식을 그대로 냅뒀더니
	잘 돌아간다. 왜 그럴까?

	2/16 C는 엽기적인 언어라는 사실을 알았다.
	배열 인덱스는 0부터 시작하는게 맞지만,
	심지어 음수를 집어넣어도 조건만(접근 가능한 메모리를 가리키고 있다면)
	맞는다면 오류도 안뿌리고 알아서 잘 돌아간다.

	알고보니까 부적절한 참조가 일어난건데 내가 모르고 계속 쓴것 같다.
	C언어가 이렇게 위험합니다. -> 수정함
*/

#include <stdlib.h>
#include <stdio.h>
#define SIZE 10

int top = -1;
int stack[SIZE] = 
	{0,0,0,0,0,0,0,0,0,0};

// 스택에 데이터를 집어 넣는다.
void push(int d)
{
	if(top >= SIZE){
		printf("stack overflow\n");
	} else {
		top++;
		stack[top] = d;
	}
}

// 스택에서 데이터를 뺀다.
// 즉, 맨 위에 있는 데이터를 제거한다.
void pop()
{
	if(top == -1){
		printf("stack underflow\n");
	} else {
		printf("pop된 값은? %d\n", stack[top]);
		stack[top] = 0;
		top--;
	}
}


// 현재 스택에 담겨있는 데이터를 전부 출력한다.
void display()
{
	if(top == -1){
		printf("empty\n");
		return;
	}

	int i, j;

	for(i = top; i >= 0; i--){	
		putc('+', stdout);

		// 양 옆으로 여백이 2칸은 필요하다.
		for(j = 0; j < get_int_position(stack[i]) + 2; j++)
			putc('-', stdout);

		printf("+\n");
		printf("| %d |\n", stack[i]);
	}

	printf("\n");
}

// 정수의 자리수를 얻는 함수
// 음수 안됌, 100억이상도 판별 불가능

// 나중에 기수 정렬(Radix sort)에서 중요한 개념으로 사용되므로 주의깊게 볼 것
int get_int_position (int tar)
{
	// 곱셈에 대한 항등원
	int i = 1;
	// 어떤 정수도 최소 1자리수라는 사실은 보장된다.
	int result = 1;

	while(tar/(10 * i) != 0){
		i *= 10;
		result++;
	}

	return result;
}

int main(){

	int menu=0;
	int data=0;

	while(menu <= 3)
	{	printf("메뉴 선택 1. 푸시    2. 팝    3. 스택보기 4.종료\n");
		scanf("%d", &menu);

		switch (menu)
		{
			case 1:
				printf("스택에 푸시할 값을 입력하세요");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
				break;
			default :
				printf("잘못된 메뉴 입력");
				break;

		}
	}
}

