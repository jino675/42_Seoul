/*
No. 30 [Professional] 단어가 등장하는 횟수
참여자 70 제출 535 배점 100
Problem제출이력정답
시간 : 20개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 2초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


독서광 동철이는 책을 정말 꼼꼼히 읽는다. 그 증거로, 책에서 어떤 단어가 몇 번 등장하는지 물어보면 정확하게 그 답을 맞춰내는 신기한 능력이 있다.

그런데, 특출난 능력이 있으면 누군가는 시샘을 하게 마련이다.

동철이의 친구 영수는 동철이의 이런 능력을 의심하고 있었지만, 도저히 그 답이 맞는지 세어볼 수가 없어 당신에게 도움을 요청하였다.

영수의 궁금증을 해소해주기 위하여, 책의 내용 B가 주어질 때 특정 단어 S가 등장하는 횟수를 알아내어라.

책의 내용에서 특정 단어가 등장하는 부분이 중첩될 수도 있음에 유의하여라.

예를 들어, B="ABABA"이고 S="ABA"이면 2번 등장하는 것으로 간주한다.


[입력]

첫 줄에 테스트케이스의 개수 T가 주어진다. (1 ≤ T ≤ 20)

각 테스트 케이스의 첫 번째 줄에 책의 내용 B가 주어진다.

책의 내용은 알파벳 소문자와 대문자, 그리고 숫자로만 이루어지고, 길이는 1 이상 500,000 이하이다.

각 테스트 케이스의 두 번째 줄에 찾고자 하는 단어 S가 주어진다.

찾고자 하는 단어는 알파벳 소문자와 대문자, 그리고 숫자로만 이루어지고, 길이는 1 이상 100,000 이하이다.

[출력]

각 테스트케이스마다 한 줄에 걸쳐, 테스트케이스 수 “#(TC) “를 출력하고, 단어가 등장하는 횟수를 출력한다.
 

입력
2
ababa
aba
abracadabra
ab	// Test Case 수
// Test Case 1


 
sample_input.txt
출력
#1 2
#2 2	// Test Case 1의 정답
*/
#include <iostream>
#include <cstring>

using namespace std;

// #define M 10000000019LL

char	book[500001];
char	pattern[100001];

// int			len;
int			res;

int	pi_table[100000];

void	get_pi(char *str)
{
	int	pre_idx;
	int	cur_idx;

	pre_idx = 0;
	cur_idx = -1;
	while (str[++cur_idx] != '\0') {
		if (cur_idx == 0) {
			pi_table[cur_idx] = 0;
			continue ;
		}
		while (pre_idx > 0 && str[pre_idx] != str[cur_idx])
			pre_idx = pi_table[pre_idx - 1];
		if (str[pre_idx] == str[cur_idx])
			pi_table[cur_idx] = ++pre_idx;
		else
			pi_table[cur_idx] = 0;
	}
}

void	kmp(void)
{
	int	pat_idx;
	int	cur_idx;

	pat_idx = 0;
	cur_idx = -1;
	while (book[++cur_idx] != '\0') {
		while (pat_idx > 0 && pattern[pat_idx] != book[cur_idx])
			pat_idx = pi_table[pat_idx - 1];
		if (pattern[pat_idx] == book[cur_idx]) {
			++pat_idx;
			if (pattern[pat_idx] == '\0') {
				++res;
				pat_idx = pi_table[pat_idx - 1];
			}
		}
	}
}





// long long	p_n;

// int	my_hash(char *str, int len)
// {
// 	long long	val;
// 	long long	p_i;

// 	val = 0;
// 	p_i = 1;
// 	for (int i = len - 1; i >= 0; --i) {
// 		val = (val + (long long)str[i] * p_i) % M;
// 		if (i > 0)
// 			p_i = (p_i * 2) % M;
// 	}
// 	p_n = p_i;

// 	return (val);
// }

// void	find_pattern(void)
// {
// 	int			next_idx;
// 	long long	cur_val;
// 	long long	pattern_val;

// 	len = strlen(pattern);
// 	pattern_val = my_hash(pattern, len);
// 	cur_val = my_hash(book, len);
// 	next_idx = len;
// 	while (1) {
// 		// printf("%c, cur : %lld, pattern : %lld\n", book[next_idx - len], cur_val, pattern_val);
// 		if (pattern_val == cur_val) {
// 			if (strncmp(&book[next_idx - len], pattern, len) == 0) {
// 				++res;
// 			}
// 		}
// 		if (book[next_idx] == '\0')
// 			break ;
// 		//(V + b) % x = V + m * x + Vb = (m + 1) * x + Vnew (최대)
// 		//어차피 V 와 Vb 모두 x를 넘을 수는 없으므로...
// 		//Vnew + x = V + Vb 
// 		//V = (Vnew + x - Vb) % x
// 		//Vnew = V + Vb or V + Vb - x 인데
// 		//Vnew - Vb = 0 이상 or 음수
// 		cur_val -= (book[next_idx - len] * p_n) % M;
// 		if (cur_val < 0)
// 			cur_val += M;
// 		//(a + b + c) % x = V
// 		//(p * a + p * b + p * c) % x = Vp
// 		//V = (Va + Vb + Vc) % x
// 		//Vp = (p*Va + p*Vb + p*Vc) % x
// 		//(Va + Vb + Vc) = mx + V
// 		//(p*Va + p*Vb + p*Vc) = p * (mx + V) = p*m*x + p*V
// 		//Vp = (p * V) % x

// 		cur_val = (cur_val * 2) % M;

// 		//(V + b) % x = (V + Vb) % x

// 		cur_val = (cur_val + book[next_idx]) % M;
// 		++next_idx;
// 	}
// }

int	main(void)
{
	int	tc;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> book;
		cin >> pattern;
		// find_pattern();
		get_pi(pattern);
		kmp();
		cout << "#" << i << " " << res << "\n";
		res = 0;
	}
	return (0);
}


// #include <iostream>
// #include <cstring>

// using namespace std;

// #define M 10000000019

// // char	book[500001];
// // char	pattern[100001];
// string	book;
// string	pattern;

// int			len;
// int			res;
// long long	p_n;

// int	my_hash(string &str, int len)
// {
// 	long long	val;
// 	long long	p_i;

// 	val = 0;
// 	p_i = 1;
// 	for (int i = len - 1; i >= 0; --i) {
// 		val = (val + (long long)str[i] * p_i) % M;
// 		if (i > 0)
// 			p_i = (p_i * 2) % M;
// 	}
// 	p_n = p_i;

// 	return (val);
// }

// void	find_pattern(void)
// {
// 	int			next_idx;
// 	long long	cur_val;
// 	long long	pattern_val;

// 	len = pattern.size();
// 	pattern_val = my_hash(pattern, len);
// 	cur_val = my_hash(book, len);
// 	next_idx = len;
// 	while (1) {
// 		// printf("%c, cur : %lld, pattern : %lld\n", book[next_idx - len], cur_val, pattern_val);
// 		if (pattern_val == cur_val) {
// 			if (strncmp(&(book.c_str())[next_idx - len], pattern.c_str(), len) == 0) {
// 				++res;
// 			}
// 		}
// 		if (next_idx == book.size())
// 			break ;
// 		//(V + b) % x = V + m * x + Vb = (m + 1) * x + Vnew (최대)
// 		//어차피 V 와 Vb 모두 x를 넘을 수는 없으므로...
// 		//Vnew + x = V + Vb 
// 		//V = (Vnew + x - Vb) % x
// 		//Vnew = V + Vb or V + Vb - x 인데
// 		//Vnew - Vb = 0 이상 or 음수
// 		cur_val -= (book[next_idx - len] * p_n) % M;
// 		if (cur_val < 0)
// 			cur_val += M;
// 		//(a + b + c) % x = V
// 		//(p * a + p * b + p * c) % x = Vp
// 		//V = (Va + Vb + Vc) % x
// 		//Vp = (p*Va + p*Vb + p*Vc) % x
// 		//(Va + Vb + Vc) = mx + V
// 		//(p*Va + p*Vb + p*Vc) = p * (mx + V) = p*m*x + p*V
// 		//Vp = (p * V) % x
// 		cur_val = (cur_val * 2) % M;
// 		//(V + b) % x = (V + Vb) % x
// 		cur_val = (cur_val + book[next_idx]) % M;
// 		++next_idx;
// 	}

// }

// int	main(void)
// {
// 	int	tc;

// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	cin >> tc;
// 	for (int i = 1; i <= tc; ++i) {
// 		cin >> book;
// 		cin >> pattern;
// 		find_pattern();
// 		cout << "#" << i << " " << res << "\n";
// 		res = 0;
// 	}
// 	return (0);
// }