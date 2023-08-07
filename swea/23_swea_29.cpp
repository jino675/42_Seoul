/*
No. 29 문자열 교집합
참여자 80 제출 233 배점 100
Problem제출이력정답
시간 : 10개 테스트케이스를 합쳐서 C/C++의 경우 4초 / Java의 경우 8초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

문자열 집합은 알파멧 소문자로 이루어진 문자열들로 구성된 집합을 의미한다.

예를 들어 {"aba", "cdefasad", "wefawef"}은 문자열 3개로 구성된 한 개의 문자열 집합이다.

입력으로 2개의 문자열 집합이 주어졌을 때에, 두 집합에 모두 속하는 문자열 원소의 개수를 출력하는 프로그램을 작성하시오.


[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스마다 첫 번째 줄에 두 집합의 원소의 갯수를 나타내는 두 자연수 N M(1≤N, M≤105)이 주어진다.

둘째 줄에는 첫 번째 집합의 원소 문자열들이 공백을 사이에 두고 주어진다.

셋째 줄에는 두 번째 집합의 원소 문자열들이 공백을 사이에 두고 주어진다.

각 문자열은 소문자 알파벳으로만 구성되며, 길이가 1 이상 50 이하임이 보장된다.

한 집합에 같은 문자열이 두 번 이상 등장하지 않음이 보장된다.


[출력]

각 테스트 케이스마다 첫째 줄에 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력한 다음, 공백을 하나 사이에 두고 해당 테스트 케이스의 답을 출력한다.
 

입력
2
2 3
ab a
a ac ba
3 3
aa bb cc
dd cc aa

sample_input.txt
출력
#1 1
#2 2
*/
#include <iostream>
#include <cstring>
#include <list>

#define P 31
#define mod 100000

using namespace std;


// list<string>			table[100000];
// list<string>::iterator	iter;
// // char	set[100001][51];
// int		N;
// int		M;
// int		res;

// int	my_hash(string str)
// {
// 	int val;
// 	int	p_i;

// 	val = 0;
// 	p_i = 1;
// 	for (int i = 0; str[i] != '\0'; ++i) {
// 		val = (val + (str[i] * p_i)) % mod;
// 		p_i = (p_i * P) % mod;
// 	}
// 	return (val);
// }

// int	main(void)
// {
// 	int		tc;
// 	int		idx;
// 	string	buf;

// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	cin >> tc;
// 	for (int i = 1; i <= tc; ++i) {
// 		cin >> N >> M;
// 		for (int j = 1; j <= N; ++j) {
// 			cin >> buf;
// 			idx = my_hash(buf);
// 			table[idx].push_back(buf);

// 			// for (iter = table[idx].begin(); iter != table[idx].end(); ++iter) {
// 			// 	if (strcmp(*iter, set[j]) == 0) {
// 			// 		break ;
// 			// 	}
// 			// }
// 			// if (iter != table[idx].end())
// 				// printf("\nset 1 : %s %d %s\n", set[j], idx, *iter);
// 			// printf("%s %d\n", set[j], idx);
// 		}
// 		for (int j = 1; j <= M; ++j) {
// 			cin >> buf;
// 			idx = my_hash(buf);
// 			// printf("\nset_2_pre : %s %d\n", buf, idx);
// 			for (iter = table[idx].begin(); iter != table[idx].end(); ++iter) {
// 					// printf("\nset 2 : %s %d %s\n", buf, idx, *iter);
// 				if (buf == *iter) {
// 					++res;
// 					break ;
// 				}
// 			}
// 		}
// 		cout << "#" << i << " " << res << "\n";
// 		res = 0;
// 		for (int j = 0; j < 100000; ++j)
// 			table[j].clear();
// 	}
// 	return (0);
// }




list<char *>			table[100000];
list<char *>::iterator	iter;
char	set[100001][51];
int		N;
int		M;
int		res;

int	my_hash(char *str)
{
	int val;
	int	p_i;

	val = 0;
	p_i = 1;
	for (int i = 0; str[i] != '\0'; ++i) {
		val = (val + (str[i] * p_i)) % mod;
		p_i = (p_i * P) % mod;
	}
	return (val);
}

int	main(void)
{
	int		tc;
	int		idx;
	char	buf[51];

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> N >> M;
		for (int j = 1; j <= N; ++j) {
			cin >> set[j];
			idx = my_hash(set[j]);
			table[idx].push_back(set[j]);

			// for (iter = table[idx].begin(); iter != table[idx].end(); ++iter) {
			// 	if (strcmp(*iter, set[j]) == 0) {
			// 		break ;
			// 	}
			// }
			// if (iter != table[idx].end())
				// printf("\nset 1 : %s %d %s\n", set[j], idx, *iter);
			// printf("%s %d\n", set[j], idx);
		}
		for (int j = 1; j <= M; ++j) {
			cin >> buf;
			idx = my_hash(buf);
			// printf("\nset_2_pre : %s %d\n", buf, idx);
			for (iter = table[idx].begin(); iter != table[idx].end(); ++iter) {
					// printf("\nset 2 : %s %d %s\n", buf, idx, *iter);
				if (strcmp(*iter, buf) == 0) {
					++res;
					break ;
				}
			}
		}
		cout << "#" << i << " " << res << "\n";
		res = 0;
	}
	return (0);
}