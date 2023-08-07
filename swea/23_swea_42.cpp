/*
No. 42 [S/W 문제해결 응용] 6일차 - K번째 접미어
참여자 66 제출 84 배점 100
Problem제출이력정답
시간 : 10개 테스트케이스를 합쳐서 C/C++의 경우 20초 / Java의 경우 40초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

영어 소문자로 된 문자열이 있다. 문자열의 길이가 n일 때 접미어들은 문자열의 길이만큼 존재한다.

“monster”라는 문자열에는 아래 그램의 왼쪽과 같은 접미어들이 있고 사전적으로 정렬했을 경우에 아래 그림과 같이 정렬된다.
 



“monster” 문자열의 접미어들 중에서 사전적 순서로 4번째에 오는 접미어는 “onster 이다.

K값과 문자열이 주어지면 접미어들 중 사전적 순서로 K번째에 해당하는 접미어를 찾아서 출력하시오.

[입력]

가장 첫 줄은 전체 테스트 케이스의 수이다.

10개의 테스트 케이스가 표준 입력을 통하여 주어진다.

각 테스트 케이스는 정수 K 하나가 쓰여진 줄 다음에 영어 소문자로 된 문자열이 쓰인 줄로 이루어진다.

문자열의 길이는 최대 400 이다.

[출력]

각 테스트 케이스마다, 첫 줄에는 “#C”를 출력해야 하는데 C는 케이스 번호이다.

같은 줄에 빈 칸을 하나 사이에 두고 이어서 사전 순서로 K번째 나오는 부분 문자열을 출력한다.

만약 K번째 문자열이 존재하지 않는다면, “none”을 출력한다.
입력
10
4
monster
9
sesquipedalian
18
supercalifragilisticexpialidociou
. . .

input.txt
출력
#1 onster
#2 n
#3 isticexpialidociou
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
	// struct s_trie	*child[26];
	int				is_terminated;
	int				idx;
}	t_trie;

t_trie	node_pool[1000000];
int		node_count;
t_trie	*head;
int		table[401];
int		table_count;

stack<t_trie *>	st;

int		K;
char	input[401];
char	*res;

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
			if (cur_str[j] == '\0') {
				cur_node->is_terminated = 1;
				cur_node->idx = i;
				break ;
			}
			// cout << cur_str[j] << " ";
			iter = cur_node->child.find(cur_str[j]);
			if (iter == cur_node->child.end()) {
				cur_node->child.insert(make_pair(cur_str[j], &node_pool[node_count]));
				cur_node = &node_pool[node_count++];
				// cout << node_count << " ";
			}
			else
				cur_node = iter->second;
		}
	}
}

void	make_table_res()
{
	t_trie	*cur_node;
	map<char, struct s_trie *>::iterator	iter;

	table_count = 0;
	st.push(head);
	while (st.empty() != true) {
		cur_node = st.top();
		st.pop();
		if (cur_node->is_terminated == 1) {
			table[++table_count] = cur_node->idx;
			if (table_count == K) {
				res = &input[table[K]];
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
		if (K > (int)strlen(input) || K < 0)
			cout << "#" << i << " none\n";
		else {
			make_trie(input);
			make_table_res();
			cout << "#" << i << " " << res << "\n";
		}
		for (int j = 0; j < node_count; ++j) {
			node_pool[j].child.clear();
			node_pool[j].idx = 0;
			node_pool[j].is_terminated = 0;
		}
		node_count = 0;
	}
	return (0);
}