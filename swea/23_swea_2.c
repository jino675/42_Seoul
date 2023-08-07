/*
No. 2 이진수 표현
참여자 87 제출 122 배점 100
Problem제출이력정답
시간 : 10000개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 2초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

 
정수 N, M 이 주어질 때, M의 이진수 표현의 마지막 N 비트가 모두 1로 켜져 있는지 아닌지를 판별하여 출력하라.

 

[입력]

첫 번째 줄에 테스트 케이스의 수 TC가 주어진다.
이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다.
각 테스트 케이스는 다음과 같이 구성되었다.
첫 번째 줄에 정수 N, M이 주어진다. (1 ≤ N ≤ 30 , 0 ≤ M ≤ 108)

 

[출력]

각 테스트 케이스마다 한 줄씩

마지막 N개의 비트가 모두 켜져 있다면 ON

아니면 OFF 를 출력하라.

입력
5
4 0
4 30
4 47
5 31
5 62	

출력
#1 OFF
#2 OFF
#3 ON
#4 ON
#5 OFF
*/
#include <stdio.h>
#include <stdlib.h>

int	tc;
int	*N;
int	*M;
int	mask;

int main(void)
{
	int	res;

	setbuf(stdout, NULL);
	scanf("%d", &tc);
	N = (int *)malloc(sizeof(int) * tc);
	M = (int *)malloc(sizeof(int) * tc);
	for (int i = 0; i < tc; ++i)
		scanf("%d %d", &N[i], &M[i]);
	for (int i = 0; i < tc; ++i) {
		mask = 1;
		mask = (mask << N[i]) - 1;
		// printf("%x %x\n", mask, M[i]);
		res = ((mask & M[i]) == mask);
		if (res == 1)
			printf("#%d %s\n", i + 1, "ON");
		else
			printf("#%d %s\n", i + 1, "OFF");
	}
	return (0);
}
