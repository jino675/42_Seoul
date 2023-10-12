/*
강의실 배정
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	39417	11555	8522	28.829%
문제
수강신청의 마스터 김종혜 선생님에게 새로운 과제가 주어졌다. 

김종혜 선생님한테는 Si에 시작해서 Ti에 끝나는 N개의 수업이 주어지는데, 최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다. 

참고로, 수업이 끝난 직후에 다음 수업을 시작할 수 있다. (즉, Ti ≤ Sj 일 경우 i 수업과 j 수업은 같이 들을 수 있다.)

수강신청 대충한 게 찔리면, 선생님을 도와드리자!

입력
첫 번째 줄에 N이 주어진다. (1 ≤ N ≤ 200,000)

이후 N개의 줄에 Si, Ti가 주어진다. (0 ≤ Si < Ti ≤ 109)

출력
강의실의 개수를 출력하라.

예제 입력 1 
3
1 3
2 4
3 5
예제 출력 1 
2
*/
#include <iostream>
#define    UNIT 100
using namespace std;

struct node {
	int			height;
	int			s;
	int			e;
	struct node	*next;
	struct node *prev;
};

node	node_pool[400000];
int		node_pool_idx;

node	*table[10'000'001];

class SegmentList {
private:
	node	head;
	int		max_height;

	void	insert_new_node(node *cur, int s, int e, int height) {
		node	*new_node = &node_pool[node_pool_idx++];
		new_node->s = s;
		new_node->e = e;
		new_node->height = height;
		new_node->next = cur;
		new_node->prev = cur->prev;
		cur->prev->next = new_node;
		cur->prev = new_node;
		for (int i = s / UNIT; i * UNIT <= e; ++i) {
			if (s <= i * UNIT && i * UNIT <= e)
				table[i] = new_node;
		}
	}
	void	erase_node(node *cur) {
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		for (int i = cur->s / UNIT; i * UNIT <= cur->e; ++i) {
			if (cur->s <= i * UNIT && i * UNIT <= cur->e)
				table[i] = cur->prev;
		}
	}

public:
	void	clear(void) {
		node_pool_idx = 0;
		head.next = &head;
		head.prev = &head;
		insert_new_node(&head, 0, 1000'000'000, 0);
		max_height = 0;
	}
	void	push(int a, int b) {
		for (node *cur = table[a / UNIT]; cur != &head; cur = cur->next) {
			if (!(b < cur->s || cur->e < a) && cur->height + 1 > max_height)
				++max_height;
			if (a <= cur->s && cur->s <= b && b < cur->e) {
				if (cur->prev != &head && cur->prev->height == cur->height + 1) {
					cur->prev->e = b;
					cur->s = b + 1;
				}
				else {
					insert_new_node(cur, cur->s, b, cur->height + 1);
					cur->s = b + 1;
				}
				return ;
			}
			else if (cur->s < a && b < cur->e) {
				insert_new_node(cur, cur->s, a - 1, cur->height);
				insert_new_node(cur, a, b, cur->height + 1);
				cur->s = b + 1;
				return ;
			}
			else if (cur->s < a && a <= cur->e && cur->e <= b) {
				if (cur->e == b) {
					if (cur->next != &head && cur->next->height == cur->height + 1) {
						cur->next->s = a;
						cur->e = a - 1;
					}
					else {
						insert_new_node(cur, cur->s, a - 1, cur->height);
						cur->s = a;
						++cur->height;
					}
					return ;
				}
				else {
					insert_new_node(cur, cur->s, a - 1, cur->height);
					cur->s = a;
					++cur->height;
				}
			}
			else if (a <= cur->s && cur->e <= b) {
				if (cur->e == b) {
					if (cur->prev != &head && cur->prev->height == cur->height + 1) {
						if (cur->next != &head && cur->next->height == cur->height + 1) {
							cur->prev->e = cur->next->e;
							erase_node(cur->next);
							erase_node(cur);
						}
						else {
							cur->prev->e = cur->e;
							erase_node(cur);
						}
					}
					if (cur->next != &head && cur->next->height == cur->height + 1) {
						cur->e = cur->next->e;
						erase_node(cur->next);
					}
					++cur->height;
					return ;
				}
				else {
					if (cur->prev != &head && cur->prev->height == cur->height + 1) {
						cur->prev->e = cur->e;
						erase_node(cur);
					}
					else
						++cur->height;
				}
			}
		}
	}
	int		get_max_height(void) {
		return (max_height);
	}
	// void	print_all(void) {
	// 	for (node *ptr = head.next; ptr != &head; ptr = ptr->next) {
	// 		cout << "start : " << ptr->s << ", end : " << ptr->e << ", heithg : " << ptr->height << "\n";
	// 	}
	// }
};

SegmentList	sl;

int	main(void)
{
	int	N;
	int	S, T;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	sl.clear();

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> S >> T;
		sl.push(S, T - 1);
	}
	cout << sl.get_max_height() << "\n";
	// sl.print_all();

	return (0);
}