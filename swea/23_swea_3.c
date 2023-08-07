/*
No. 3 동아리실 관리하기
참여자 29 제출 35 배점 100
Problem제출이력정답
시간 : 20개 테스트케이스를 합쳐서 C/C++의 경우 30초 / Java의 경우 30초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


삼성초등학교에는 영준, 준환, 동한, 하니 이렇게 네 명이 프로그래밍 동아리에 속해있다. 부원 네 명의 이름을 편의상 A, B, C, D라고 하자.

앞으로 N일간의 활동 일정을 정해야 한다.

각 부원은 하루의 활동에 참여를 할지 하지 않을지를 정해야 하며, 어떤 부원이 참여하는지의 경우의 수는 하루에 총 16가지이다.

그런데 아무도 활동에 참여하지 않으면 동아리가 폐부 될 수 있으므로 아무도 참여를 하지 않아서는 곤란하다.

즉 실제로는 15가지 경우가 있다.

동아리 실을 여는 열쇠는 하나밖에 없고 활동이 끝나면 동아리 실을 잠가야 하기 때문에 문을 열어주기 위해 열쇠를 가진 사람은 무조건 활동에 참여해야 한다.

오늘 활동에 참여하는 사람 중에 내일 활동에도 참여하는 사람이 있다면 열쇠를 넘겨줄 수 있다.

첫 번째 날에는 A가 열쇠를 가지고 있다.

모든 활동이 끝난 다음에는 열쇠를 누가 가지고 있어도 상관이 없다.


또한 N일 동안 각 날마다 활동의 책임자가 있어서 이 책임자는 무조건 활동에 참여해야 한다.

N일 동안의 동아리 활동을 할 수 있는 경우의 수를 출력하는 프로그램을 작성하라.

(열쇠를 누구에게 넘겨주는지는 중요하지 않고 어떤 사람이 활동을 하는지 안 하는지에 따라 경우의 수를 세어야 한다.)

예를 들어 동아리실 담당자가 첫날에는 B, 둘째 날 C라고 해보자.

위의 그림에서 가능한 경우에는 1일차와 2일차에 A가 열쇠를 전달해 주면 된다.

하지만 불가능 한 경우에는 1일차 있었던 사람이 2일차에 아무도 없기 때문에 동아리 실을 유지할 수 없게 된다.
 

[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스마다 길이 10,000 이하인 하나의 문자열이 주어진다. 이 문자열은 A, B, C, D로 이루어져 있으며, i번째 문자는 i번째 날의 책임자가 누구인지를 나타낸다.


[출력]
각 테스트 케이스마다 N일 동안의 동아리 활동을 할 수 있는 경우의 수를 출력하는 프로그램을 작성하라.

이 수는 너무 커질 수 있으므로 1,000,000,007로 나눈 나머지를 출력한다.
 

입력
2
BC
ADCBBACDCBCBACBDCABDCBA	 


출력
#1 29
#2 88253169
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	char	who[5];
	char	next[4][9];
}	t_list;

t_list		list[15];
char		ref[4][9];
int			tc;
char		**input;
int			N;
long long	count;

static void	make_list(void)
{
	int		ref_idx;
	int		cur_idx;

	strcpy(list[0].who, "A");
	strcpy(list[1].who, "AB");
	strcpy(list[2].who, "AC");
	strcpy(list[3].who, "AD");
	strcpy(list[4].who, "ABC");
	strcpy(list[5].who, "ABD");
	strcpy(list[6].who, "ACD");
	strcpy(list[7].who, "ABCD");
	strcpy(list[8].who, "B");
	strcpy(list[9].who, "BC");
	strcpy(list[10].who, "BD");
	strcpy(list[11].who, "BCD");
	strcpy(list[12].who, "C");
	strcpy(list[13].who, "CD");
	strcpy(list[14].who, "D");
	strcpy(ref[0], "01234567");
	strcpy(ref[1], "145789ab");
	strcpy(ref[2], "24679bcd");
	strcpy(ref[3], "3567abde");
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 4; ++j) {
			cur_idx = -1;
			for (int k = 0; k < 8; ++k) {
				ref_idx = ref[j][k] - '0';
				if (ref_idx > 9 || ref_idx < 0)
					ref_idx = ref[j][k] - 'a' + 10;
				for (int w = 0; list[i].who[w] != '\0'; ++w) {
					if (strchr(list[ref_idx].who, list[i].who[w]) != NULL) {
						list[i].next[j][++cur_idx] = "0123456789abcdef"[ref_idx];
						break ;
					}
				}
			}
			// printf("%d-%c, %s\n", i, j + 'A', list[i].next[j]);
		}
	}
}

static void	DFS(char *shift, int pre_idx, int next_date)
{
	int	next_date_idx;
	int	next_idx;

	next_date_idx = shift[next_date] - 'A';
	if (N != 1 && next_date == N - 1) {
		count += strlen(list[pre_idx].next[next_date_idx]);
		return ;
	}
	else if (N == 1 && next_date == N - 1) {
		if (next_date_idx == 0)
			count += 8;
		else
			count += 4;
		return ;
	}
	for (int i = 0; list[pre_idx].next[next_date_idx][i] != '\0'; ++i) {
		next_idx = list[pre_idx].next[next_date_idx][i] - '0';
		if (next_idx > 9 || next_idx < 0)
			next_idx = list[pre_idx].next[next_date_idx][i] - 'a' + 10;
		if (next_date == 0 && next_idx > 7)
			continue ;
		// printf("i : %d, next_date : %d, next_idx : %d, count : %lld\n", i, next_date, next_idx, count);
		DFS(shift, next_idx, next_date + 1);
	}
}

int	main(void)
{
	char	buf[10001];

	make_list();
    setbuf(stdout, NULL);
	scanf("%d", &tc);
	input = (char **)calloc(tc, sizeof(char *));
	for (int i = 0; i < tc; ++i) {
		scanf("%s", buf);
		input[i] = (char *)calloc(strlen(buf) + 1, sizeof(char));
		strcpy(input[i], buf);
	}
	for (int i = 0; i < tc; ++i) {
		count = 0;
		N = strlen(input[i]);
		DFS(input[i], 7, 0);
		printf("#%d %lld\n", i + 1, count % 1000000007);
	}
	return (0);
}