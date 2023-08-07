/*
No. 28 스팟마트
참여자 48 제출 232 배점 100
Problem제출이력정답
시간 : 15개 테스트케이스를 합쳐서 C/C++의 경우 7초 / Java의 경우 14초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.
 

인재개발원 스팟마트에서 과자를 무료로 나눠주는 행사를 진행하고 있다!


스팟마트에는 N봉지의 과자가 좌에서 우로 나열되어 있으며, 이 중 i번째 봉지는 Ai개의 조각을 가지고 있다.


추가적으로 M개의 봉지가 더 제공되며, 이 중 i번째 봉지는 Bi개의 조각을 가지고 있다.


당신은 좌에서 우로 나열되어 있는 N봉지의 과자 사이에 M개의 봉지를 아무 곳에나 (시작점, 끝점, 봉지 사이) 끼워 넣을 수 있다.

이렇게 되면 N+M 개의 봉지가 좌에서 우로 나열되며, 그 중 초기의 N 봉지는 상대적 순서를 유지하는 형태가 될 것이다.

당신은 이렇게 만들어 놓은 리스트를 좌에서 우로 순서대로 걸어가면서 뽑아간다.

리스트에 있는 과자를 고를 수도 있고, 안 고를 수도 있지만, 행사의 규칙에 의하면 과자 한 봉지를 가져갔다면 그 다음 과자 봉지는 절대 가져갈 수 없다.

다른 말로 하면, 리스트에서 연속된 과자를 고를 수 없다.

가장 많은 과자 조각을 가져갈 수 있는 방법은 무엇일까?

 

[입력]

 

첫 번째 줄에 테스트 케이스의 수 TC가 주어진다.

이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다.

각 테스트 케이스는 다음과 같이 구성되었다.

 

첫 번째 줄에는 N이 주어진다. (1 ≤ N ≤ 3,000)

 

이후 N개의 줄에 Ai가 주어진다. (1 ≤ Ai  ≤ 100,000)

 

N+2번째 줄에는 M이 주어진다. (0 ≤ M ≤ 100)

 

이후 M개의 줄에 Bi가 주어진다. (1 ≤ Bi  ≤ 100,000)

 

 

[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

각 테스트 케이스마다 한 줄씩, 최대로 가져갈 수 있는 과자의 개수를 출력하라.

입력
1
5
10
12
6
14
7
3
8
1
2	// 테스트 케이스 개수
// 첫 번째 테스트 케이스 N = 5
 
 
 
 
 
//첫 번째 테스트 케이스 M = 3


 
sample_input.txt
출력
#1 44	// 첫 번째 테스트 케이스 결과
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int	table[3001][101][101][2];
int	N;
int	M;
int	val_n[3000];
int	val_m[100];

int	check_in_this_view(int n_i, int pre_picked_m, int pre_passed_m, int can_pick_now)
{
	int	&cur_res = table[n_i][pre_picked_m][pre_passed_m][can_pick_now];

	if (cur_res != -1)
		return (cur_res);
	cur_res = 0;
	if (can_pick_now == 1) {
		if (n_i < N) {
			cur_res = max(cur_res, check_in_this_view(n_i + 1, pre_picked_m, pre_passed_m, 0) + val_n[n_i]);
			cur_res = max(cur_res, check_in_this_view(n_i + 1, pre_picked_m, pre_passed_m, 1));
		}
		if (pre_picked_m + pre_passed_m < M) {
			cur_res = max(cur_res, check_in_this_view(n_i, pre_picked_m + 1, pre_passed_m, 0) + val_m[pre_picked_m]);
			cur_res = max(cur_res, check_in_this_view(n_i, pre_picked_m, pre_passed_m + 1, 1));
		}
	}
	else {
		if (n_i < N)
			cur_res = max(cur_res, check_in_this_view(n_i + 1, pre_picked_m, pre_passed_m, 1));
		if (pre_picked_m + pre_passed_m < M)
			cur_res = max(cur_res, check_in_this_view(n_i, pre_picked_m, pre_passed_m + 1, 1));
	}
	return (cur_res);
}

int	main(void)
{
	int	tc;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> N;
		for (int j = 0; j < N; ++j)
			cin >> val_n[j];
		cin >> M;
		for (int j = 0; j < M; ++j)
			cin >> val_m[j];
		sort(val_m, val_m + M, greater<int>());
		memset(table, -1, sizeof(table));
		check_in_this_view(0, 0, 0, 1);
		// for (int j = 0; j <= N; ++j) {
		// 	for (int k = 0; k <= M; ++k) {
		// 		for (int w = 0; w <= M; ++w) {
		// 			for (int q = 0; q < 2; ++q)
		// 				printf("n = %d, picked = %d, passed = %d, can_now = %d, res = %d\n", j, k, w, q, dp[j][k][w][q]);
		// 		}
		// 	}
		// 	cout << "\n";
		// }
		cout << "#" << i << " " << table[0][0][0][1] << "\n";
	}
	return (0);
}