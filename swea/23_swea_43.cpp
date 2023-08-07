/*
No. 43 [S/W 문제해결 응용] 6일차 - K번째 문자열
참여자 59 제출 74 배점 100
Problem제출이력정답
시간 : 10개 테스트케이스를 합쳐서 C/C++의 경우 20초 / Java의 경우 20초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

영어 소문자로 된 문자열이 있다.

이 문자열의 부분문자열은 문자열의 두 위치를 골라서, 이 사이의 연속한 문자열을 뽑아낸 것이다.

두 위치가 같을 때는 길이가 1인 부분 문자열이 된다.

예를 들어, 문자열 love의 모든 부분 문자열은 l, o, v, e, lo,ov, ve, lov, ove, love이다.

또 다른 예로, 문자열 food의 부분 문자열은 f, o, d, fo, oo,od, foo, ood, food가 있다. 동일한 문자열 o가 두번 나오지만, 중복을 제거한 것에 유의하자.
 
이 문자열에 대해서 사전 순서로 정렬을 하는 것을 고려해보자.

두 문자열을 왼쪽부터 오른쪽으로 비교해나가면서, 처음으로 다른 글자가 나왔을 때 알파벳 순으로 먼저 나오는 문자가 있는 쪽이 순서가 앞이다.

다른 글자가 나오기 전에 한 문자열이 끝난다면 이 문자열이 순서가 앞이다.

아래 그림은 사전 순서로 정렬하는 예이다 (문제풀이와는 관계 없는 일반적인 사전 순서로 정렬하는 예시임).
 



위의 예로 든 문자열 love, food에 대해 사전 순서로 정렬하면 결과는 다음과 같다.
 
순서	love의 부분 문자열	food의 부분 문자열
1	e	d
2	l	f
3	lo	fo
4	lov	foo
5	love	food
6	o	o
7	ov	od
8	ove	oo
9	v	ood
10	ve	 
문자열과 정수 K가 주어지고, 이 문자열의 부분 문자열들을 사전 순서대로 나열하였을 때 K번째에 오는 문자열을 출력하는 프로그램을 작성하시오.

다음의 입출력 조건을 준수하시오.
 
[입력]

가장 첫 줄은 전체 테스트 케이스의 수이다.

각 테스트 케이스는 정수 K 하나가 쓰여진 줄 다음에 영어 소문자로 된 문자열이 쓰인 줄로 이루어진다.

문자열의 길이는 최대 400이다.
 
[출력]

각 테스트 케이스마다, 첫 줄에는 “#C”를 출력해야 하는데 C는 케이스 번호이다.

같은 줄에 빈 칸을 하나 사이에 두고 이어서 사전 순서로 K번째 나오는 부분 문자열을 출력한다.

만약 K번째 문자열이 존재하지 않는다면, “none”을 출력한다.
입력
3
7
love
10
food
281
tfbpqyuekmsonzgdlvjhcawxr
 

input.txt
출력
#1 ov
#2 none
#3 v
. . .
*/
#include <iostream>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

typedef struct s_trie
{
	map<char, struct s_trie *> child;
	int				start;
	int				len;
}	t_trie;

t_trie	node_pool[80201];
int		node_count;
t_trie	*head;
int		cur_count;

stack<t_trie *>	st;

int		K;
char	input[401];
char	res[401];


void	make_trie(char *str)
{
	// int		idx;
	char	*cur_str;
	t_trie	*cur_node;

	map<char, struct s_trie *>::iterator	iter;

	for (int i = strlen(str) - 1; i >= 0; --i) {
		cur_str = &str[i];
		cur_node = head;
		// cout << "\n=========" << cur_str << "=========\n";
		for (int j = 0; ; ++j) {
			if (cur_str[j] == '\0')
				break ;
			// cout << cur_str[j] << " ";
			iter = cur_node->child.find(cur_str[j]);
			if (iter == cur_node->child.end()) {
				cur_node->child.insert(make_pair(cur_str[j], &node_pool[node_count]));
				cur_node = &node_pool[node_count++];
				cout << node_count << " ";
			}
			else
				cur_node = iter->second;
			cur_node->start = i;
			cur_node->len = j + 1;	
		}
	}
}

void	make_table_res()
{
	t_trie	*cur_node;
	map<char, struct s_trie *>::iterator	iter;

	cur_count = 0;
	st.push(head);
	while (st.empty() != true) {
		cur_node = st.top();
		st.pop();
		if (cur_node != head) {
			// for (int i = 0; i < cur_node->len; ++i)
			// 	cout << input[cur_node->start + i];
			// cout << "\n";
			++cur_count;
			if (cur_count == K) {
				strncpy(res, &input[cur_node->start], cur_node->len);
				res[cur_node->len] = '\0';
				return ;
			}
		}
		if (cur_node->child.empty() != true) {
			iter = cur_node->child.end();
			do {
				--iter;
				st.push(iter->second);
			} while (iter != cur_node->child.begin());
		}
	}
	// for (int i = 1; i <= table_count; ++i) {
	// 	cout << &input[table[i]] << "\n";
	// }
}

int	main(void)
{
	int	tc;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		head = &node_pool[node_count++];
		cin >> K >> input;
		make_trie(input);
		make_table_res();
		if (res[0] == '\0')
			cout << "#" << i << " none\n";
		else
			cout << "#" << i << " " << res << "\n";
		for (int j = 0; j < node_count; ++j) {
			node_pool[j].child.clear();
			node_pool[j].start = 0;
			node_pool[j].len = 0;
		}
		node_count = 0;
		res[0] = '\0';
		while (st.empty() != true)
			st.pop();
	}
	return (0);
}