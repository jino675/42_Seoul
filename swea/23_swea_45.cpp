/*
No. 45 Segment Tree 연습 - 1
참여자 33 제출 60 배점 100
Problem제출이력정답
시간 : 10개 테스트케이스를 합쳐서 C/C++의 경우 4초 / Java의 경우 4초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
길이가 n인 수열 a0, a1, ⋯, an-1 (0 ≤ ai ≤ 109) 에서 아래 두 가지 쿼리를 처리하는 프로그램을 작성하라


•  0 i x    :    ai 를 x로 바꾼다. (0 ≤ i ≤ n - 1, 0 ≤ x ≤ 109)
•  1 l r    :    max(al, al+1, ⋯, ar-1) - min(al, al+1, ⋯, ar-1)를 출력한다. (0 ≤ l < r ≤ n)
 
[입력]
첫 번째 줄에 테스트 케이스의 수 T 가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 배열의 길이 n(1 ≤ n ≤ 105)과 쿼리의 개수 q(1 ≤ q ≤ 105)가 주어진다.
두 번째 줄에는 배열 a가 주어진다.
세 번째 줄부터 q개 줄에 걸쳐 쿼리가 주어진다.
 

[출력]
각 테스트 케이스마다 1번 쿼리의 결과를 공백으로 구분하여 출력한다.

입력
2
5 5
1 2 3 4 5
1 0 5
1 1 4
0 2 9
1 0 5
1 1 4
3 4
0 5 10
1 0 3
0 0 5
0 2 5
1 0 3

sample_in.txt
출력
#1 4 2 8 7
#2 10 0
*/
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int	max_tree[300000];
int	min_tree[300000];

int	N;
int	n2;
int	depth;
int	Q;

int	res;
int	max_val;
int	min_val;

void	make_tree(void)
{
	int	cur;
	int	child_1, child_2;

	cur = n2 - 1;
	while (cur > 0) {
		child_1 = cur * 2;
		child_2 = cur * 2 + 1;
		max_tree[cur] = max(max_tree[child_1], max_tree[child_2]);
		min_tree[cur] = min(min_tree[child_1], min_tree[child_2]);
		--cur;
	}
}

void	get_n2_depth(void)
{
	int	count;

	count = 0;
	for (int i = N; i > 0; i >>= 1) {
		++count;
	}
	--count;
	if (N > (1 << count))
		++count;
	n2 = 1 << count;
	depth = count;
}

void	update(int idx, int	val)
{
	int	cur;
	int	child_1, child_2;

	cur = n2 + idx;
	while (cur > 0) {
		if (cur >= n2) {
			max_tree[cur] = val;
			min_tree[cur] = val;
		}
		else {
			child_1 = cur * 2;
			child_2 = cur * 2 + 1;
			max_tree[cur] = max(max_tree[child_1], max_tree[child_2]);
			min_tree[cur] = min(min_tree[child_1], min_tree[child_2]);
		}
		cur = cur / 2;
	}
}

void	find_max_min(int lev, int cur_idx, int cur_l, int cur_r)
{
	int	start, end, mid;	//현재 노드의 범위와 중간값 (인덱스 기준)
	int	length;

	length = 1 << (depth - lev);
	start = length * (cur_idx - (1 << lev));
	end = start + length - 1;
	if (cur_l == start && cur_r == end) {	//현재 노드의 범위와 완전히 같을 때만
		if (max_tree[cur_idx] > max_val)
			max_val = max_tree[cur_idx];
		if (min_tree[cur_idx] < min_val)
			min_val = min_tree[cur_idx];
		return ;
	}
	mid = start + (end - start) / 2;
	if (cur_l <= mid) {
		if (mid < cur_r)
			find_max_min(lev + 1, cur_idx * 2, cur_l, mid);
		else
			find_max_min(lev + 1, cur_idx * 2, cur_l, cur_r);
	}
	if (cur_r >= mid + 1) {
		if (mid + 1 > cur_l)
			find_max_min(lev + 1, cur_idx * 2 + 1, mid + 1, cur_r);
		else
			find_max_min(lev + 1, cur_idx * 2 + 1, cur_l, cur_r);
	}
}

int	main(void)
{
	int	tc;
	int	input;
	int	cmd, idx, x, l, r;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> N >> Q;
		get_n2_depth();
		for (int j = 0; j < n2; ++j) {
			if (j < N) {
				cin >> input;
				max_tree[n2 + j] = input;
				min_tree[n2 + j] = input;
			}
			else {
				max_tree[n2 + j] = 0;
				min_tree[n2 + j] = INT_MAX;
			}
		}
		make_tree();
		cout << "#" << i;
		for (int j = 0; j < Q; ++j) {
			cin >> cmd;
			if (cmd == 0) {
				cin >> idx >> x;
				update(idx, x);
			}
			if (cmd == 1) {
				cin >> l >> r;
				max_val = 0;
				min_val = INT_MAX;
				if (r < N)
					find_max_min(0, 1, l, r - 1);
				else
					find_max_min(0, 1, l, n2 - 1);
				res = max_val - min_val;
				cout << " " << res;
			}
		}
		cout << "\n";
	}
	return (0);
}