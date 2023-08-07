/*
No. 1 [Pro] 전자상가
참여자 0 제출 0 배점 100
Problem제출이력정답
시간 : 25개 테스트케이스를 합쳐서 C/C++의 경우 3초 / Java의 경우 3초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
 [제한 사항]

 

시간

 25개 테스트케이스를 합쳐서 C++ 의 경우 3초 / Java 의 경우 3초 

메모리

 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내

 

  ①   C 또는 C++로 답안을 작성하시는 응시자께서는 검정시스템에 제출 시, Language 에서 C++ 를 선택하신 후 제출하시기 바랍니다.

  ②   Main 과 User Code 부분으로 구성되어 있습니다.

  ㅇ   A.  Main         : 수정할 수 없는 코드이며, 채점 시 비 정상적인 답안 검출 등 평가를 위한 로직이 추가 될 수 있습니다.

  ㅇ   B.  User Code  : 실제 응시자가 작성해야 하는 코드이며, 제출 시에는 표준 입출력 함수가 포함되어 있으면 안 됩니다.

  ③   Local PC 에서 프로그래밍 시 유의 사항

  ㅇ   A.  2개의 파일을 생성하셔야 합니다. ( main.cpp / solution.cpp 또는 Solution.java / UserSolution.java )

  ㅇ   B.  Main 부분의 코드를 main.cpp 또는 Solution.java 에 복사해서 사용하시기 바랍니다.

  ㅇ   C.  sample_input.txt 를 사용하시기 위해서는 Main 부분의 코드 내에

  ㅇ   C.  표준 입력을 파일로 전환하는 코드 ( 주석처리 되어 있음 ) 의 주석을 풀어서 사용하시면 됩니다.

  ㅇ   D.  User Code 부분의 코드를 작성하신 후 서버에 제출하실 때,

  ㅇ   D.  디버깅을 위한 표준 입출력 함수를 모두 삭제 또는 주석 처리해 주셔야 합니다.

  ④   문제 내에 제약조건을 모두 명시하지 않으므로 주어지는 코드를 분석하셔야 합니다.

  ⑤   코드는 개발 언어에 따라 상이할 수 있으므로, 작성할 언어를 기준으로 분석하셔야 합니다.

 

※ 본 문제는 임직원의 S/W 문제해결 역량 향상을 위한 Professional 실전형 연습문제이며

함께 제공되는 Testcase 또한 학습을 위한 연습용입니다.

 

[문제 설명]

2개의 부품 창고를 가진 컴퓨터 부품 업체가 있다.

업체는 소비자의 예산에 맞춰 컴퓨터가 최대한의 성능을 내도록 견적을 짜주는 서비스를 제공한다.

컴퓨터 조립 시에는 3 종류의 부품을 각각 하나씩 선택하며, 그 중 가장 성능이 낮은 부품의 성능이 컴퓨터의 성능이 된다.

소비자가 지불하는 가격은 부품 가격과 운송료의 합산이다. 만약 최대 성능을 내는 조합이 여러 개면 가장 가격이 낮은 조합으로 선택한다.

한 창고의 부품으로만 선택하는 경우, 그 곳에서 바로 출고한다.

두 창고의 부품이 모두 필요하다면, 운송료를 지불하고 부품을 모은 후 출고한다.

 



각 창고에 입고된 부품의 목록이 [Fig. 1]과 같고 운송료가 50일 때, 예산이 400인 소비자가 제품을 의뢰했다고 하자.



창고 0의 부품만 고르면 [Fig. 2–(a)]와 같이 100 + 220 + 77 = 397의 비용으로 부품의 성능 200, 120, 50 중 최소인 50의 성능을 갖는 컴퓨터를 조립할 수 있다.

창고 1의 부품만 고르면 [Fig. 2–(b)]와 같이 150 + 120 + 130 = 400의 비용으로 부품의 성능 150, 100, 70 중 최소인 70의 성능을 갖는 컴퓨터를 조립할 수 있다.



창고 0, 1에서 모두 부품을 고르면 [Fig. 3]과 같이 부품값 100 + 120 + 88 = 308에 운송료 50을 더해 358의 비용으로 부품의 성능 200, 100, 150 중 최소인 100의 성능을 갖는 컴퓨터를 조립할 수 있고,

이 조합이 주어진 예산 내에서 최대의 성능을 내는 조합이다.

이와 같이 각 창고의 부품 목록을 관리하고 소비자의 주문을 처리하는 프로그램을 구현하라.

 

아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 다른 언어에 대해서는 제공되는 Main과 User Code를 참고하라.

 

아래는 User Code 부분에 작성해야 하는 API 의 설명이다. 

void init(int mCharge)

각 테스트 케이스의 처음에 호출되며, 창고 간 운송료를 알려준다.

기존의 부품 목록은 모두 초기화된다.

 

Parameters

    mCharge : 창고 간 운송료 ( 1 ≤ mCharge ≤ 100,000 )

int stock(int mType, int mPrice, int mPerformance, int mPosition)

부품 목록에 새로운 부품을 추가한다.

종류와 가격, 성능이 모두 같은 입력이 testcase 내에서 중복되어 들어오지 않는다.

 

Parameters

    mType       : 부품 종류             ( 0 ≤ mType ≤ 2 )

    mPrice       : 부품 가격             ( 1 ≤ mPrice ≤ 100,000 )

    mPerformance: 부품 성능             ( 1 ≤ mPerformance ≤ 1,000,000 )

    mPosition    : 부품이 있는 창고 번호 ( 0 ≤ mPosition ≤ 1 )

 

Returns

    입고된 창고에 동일한 type인 부품의 가짓수를 반환한다.

Result order(int mBudget)

소비자의 예산이 mBudget일 때 예산 안에서 최대의 성능을 내는 부품 조합을 선택한다.

같은 성능이면 가격이 가장 낮은 조합을 선택한다.

부품이 출고되면 즉각 채워 넣으므로 품절되지 않는다.

 

Parameters

    mBudget: 소비자의 예산 ( 1 ≤ mBudget ≤ 500,000 )

 

Returns

    주어진 예산으로 조립이 가능할 경우, Result 구조체의 mPerformance에 컴퓨터의 성능을, mPrice에 컴퓨터의 가격을 반환한다.

    주어진 예산으로 조립이 불가능할 경우, mPerformance와 mPrice 모두 0을 반환한다.

 

[예제]

아래의 예제는 Testcase 1번의 내용을 기술한다.

Order

Function

return

Figure

1

init(50)

 

 

2

stock(0, 100, 200, 0)

1

 

3

stock(0, 200, 100, 0)

2

 

4

stock(1, 220, 120, 0)

1

 

5

stock(1, 330, 160, 0)

2

 

6

stock(2, 77, 50, 0)

1

 

7

stock(2, 88, 150, 0)

2

 

8

stock(0, 150, 150, 1)

1

 

9

stock(0, 250, 300, 1)

2

 

10

stock(1, 120, 100, 1)

1

 

11

stock(1, 450, 200, 1)

2

 

12

stock(2, 300, 200, 1)

1

 

13

stock(2, 130, 70, 1)

2

 

14

order(400)

mPrice = 358

mPerformance = 100

Fig. 3

 

(순서 14) 순서 14까지의 내용은 본문에 설명된 것과 동일하다.

 

15

order(450)

mPrice = 408

mPerformance = 120

Fig. 4

16

order(346)

mPrice = 0

mPerformance = 0

 

 



(순서 15) [Fig. 4]와 같이 창고 0에서만 선택하면 408의 비용으로 120의 성능을 갖는 컴퓨터를 조립할 수 있다.

(순서 16) 346의 예산으로는 조립이 불가능하다.

 

[제약사항]

1. 각 테스트 케이스 시작 시 init() 함수가 호출된다.

2. 각 테스트 케이스에서 stock() 함수의 호출 횟수는 4,000 이하이다.

3. 각 테스트 케이스에서 order() 함수의 호출 횟수는 400 이하이다.

 

[입출력]

입출력은 제공되는 Main 부분의 코드에서 처리하므로 User Code 부분의 코드에서는 별도로 입출력을 처리하지 않는다.

Sample input 에 대한 정답 출력 결과는 “#TC번호 결과” 의 포맷으로 보여지며 결과가 100 일 경우 정답, 0 일 경우 오답을 의미한다.

*/
#include <unistd.h>
#include <iostream>
#include <map>
#include <functional>

using namespace std;

typedef struct s_warehouse
{
	multimap<int, int, greater<int> >	type[3];
	int									cnt[3];
}	t_warehouse;

struct Result
{
	int mPrice;
	int mPerformance;
};

t_warehouse	house[3];
int			charge;

void init(int mCharge)
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			house[i].type[j].clear();
			house[i].cnt[j] = 0;
		}
	}
	charge = mCharge;
}

int stock(int mType, int mPrice, int mPerformance, int mPosition)
{
	house[mPosition].type[mType].insert({mPerformance, mPrice});
	house[2].type[mType].insert({mPerformance, mPrice});
	++house[mPosition].cnt[mType];
	return (house[mPosition].cnt[mType]);
}

Result	find_res_each(int budget, int mPosition)
{
	int		max_idx;
	Result	res;

	multimap<int, int, greater<int> >::iterator	cur_iter[3];
	multimap<int, int, greater<int> >::iterator	next_iter[3];
	multimap<int, int, greater<int> >::iterator	perform_min;
	multimap<int, int, greater<int> >::iterator	price_min;

	for (int i = 0; i < 3; ++i) {
		cur_iter[i] = house[mPosition].type[i].begin();
		while (cur_iter[i] != house[mPosition].type[i].end()) {
			if (cur_iter[i]->second <= budget - 2)
				break ;
			else
				++cur_iter[i];
		}
		if (cur_iter[i] == house[mPosition].type[i].end()) {
			res.mPerformance = 0;
			res.mPrice = 0;
			return (res);
		}
		if (i == 0)
			perform_min = cur_iter[0];
		else if (cur_iter[i]->first < perform_min->first)
			perform_min = cur_iter[i];
	}

	while (1) {
		res.mPrice = 0;
		for (int i = 0; i < 3; ++i) {
			if (cur_iter[i] == perform_min) {
				res.mPerformance = cur_iter[i]->first;
				res.mPrice += cur_iter[i]->second;
				continue ;
			}
			price_min = cur_iter[i];
			int	temp_cnt = 0;
			while (cur_iter[i] != house[mPosition].type[i].end()) {
				if (cur_iter[i]->first < perform_min->first) {
					if (temp_cnt != 0)
						--cur_iter[i];
					break ;
				}
				if (cur_iter[i]->second < price_min->second)
					price_min = cur_iter[i];
				++cur_iter[i];
				++temp_cnt;
			}
			cur_iter[i] = price_min;
			res.mPrice += cur_iter[i]->second;
		}

		if (res.mPrice <= budget)
			return (res);

		max_idx = -1;
		for (int i = 0; i < 3; ++i) {
			next_iter[i] = cur_iter[i];
			while (next_iter[i] != house[mPosition].type[i].end()) {
				if (next_iter[i]->second < cur_iter[i]->second)
					break ;
				else
					++next_iter[i];
			}
			if (next_iter[i] == house[mPosition].type[i].end()) {
				continue ;
			}
			if (max_idx == -1)
				max_idx = i;
			else if (next_iter[i]->first > next_iter[max_idx]->first)
				max_idx = i;
		}
		if (max_idx == -1) {
			res.mPerformance = 0;
			res.mPrice = 0;
			return (res);
		}
		else {
			cur_iter[max_idx] = next_iter[max_idx];
			perform_min = cur_iter[max_idx];
		}
	}
}


Result order(int mBudget)
{
	Result	res;
	Result	temp[3];

	res.mPerformance = 0;
	res.mPrice = 0;
	for (int i = 0; i < 3; ++i) {
		if (i < 2)
			temp[i] = find_res_each(mBudget, i);
		else {
			temp[i] = find_res_each(mBudget - charge, i);
			if (temp[i].mPerformance != 0)
				temp[i].mPrice += charge;
		}
		if (res.mPerformance == 0)
			res = temp[i];
		else if (temp[i].mPerformance > res.mPerformance)
			res = temp[i];
		else if (temp[i].mPerformance == res.mPerformance) {
			if (temp[i].mPrice < res.mPrice)
			res = temp[i];
		}
		// printf("#%d, price : %d, perform : %d\n", i, temp[i].mPrice, temp[i].mPerformance);
	}
	// printf("res, price : %d, perform : %d\n", res.mPrice, res.mPerformance);
	return res;
}


// Result	find_res_both(int budget)
// {
// 	int		check;
// 	int		max_idx;
// 	int		temp_ware;
// 	int		max_ware;
// 	Result	res;

// 	multimap<int, int, greater<int>>::iterator	temp_iter[2][3];
// 	multimap<int, int, greater<int>>::iterator	cur_iter[3];
// 	multimap<int, int, greater<int>>::iterator	temp_next[2][3];
// 	multimap<int, int, greater<int>>::iterator	next_iter[3];
// 	multimap<int, int, greater<int>>::iterator	perform_min;
// 	multimap<int, int, greater<int>>::iterator	price_min;


// 	for (int i = 0; i < 3; ++i) {
// 		check = 0;
// 		for (int j = 0; j < 2; ++j) {
// 			temp_iter[j][i] = house[j].type[i].begin();
// 			while (temp_iter[j][i] != house[j].type[i].end()) {
// 				if (temp_iter[j][i]->second <= budget - 2)
// 					break ;
// 				else
// 					++temp_iter[j][i];
// 			}
// 			if (temp_iter[j][i] == house[j].type[i].end())
// 				check += j + 1;
// 		}
// 		if (check == 3) {
// 			res.mPerformance = 0;
// 			res.mPrice = 0;
// 			return (res);
// 		}
// 		else if (check == 0) {
// 			if (temp_iter[0][i]->first > temp_iter[1][i]->first)
// 				cur_iter[i] = temp_iter[0][i];
// 			else if (temp_iter[0][i]->first == temp_iter[1][i]->first){
// 				if (temp_iter[0][i]->second < temp_iter[1][i]->second)
// 					cur_iter[i] = temp_iter[0][i];
// 				else
// 					cur_iter[i] = temp_iter[1][i];
// 			}
// 			else
// 				cur_iter[i] = temp_iter[1][i];
// 		}
// 		else if (check == 1)
// 			cur_iter[i] = temp_iter[1][i];
// 		else if (check == 2)
// 			cur_iter[i] = temp_iter[0][i];
// 		if (i == 0) {
// 			perform_min = cur_iter[0];
// 		}
// 		else if (cur_iter[i]->first < perform_min->first)
// 			perform_min = cur_iter[i];
// 	}

// 	while (1) {
// 		// for (int i = 0; i < 3; ++i)
// 		// 	printf("type_%d) Perform : %d Price : %d\n", i, cur_iter[i]->first, cur_iter[i]->second);
// 		// usleep(100 * 1000);
// 		// printf("total) Perform : %d Price : %d Budget : %d\n\n", res.mPerformance, res.mPrice, budget);

// 		res.mPrice = 0;
// 		for (int i = 0; i < 3; ++i) {
// 			if (cur_iter[i] == perform_min) {
// 				res.mPerformance = cur_iter[i]->first;
// 				res.mPrice += cur_iter[i]->second;
// 				continue ;
// 			}
// 			price_min = cur_iter[i];
// 			for (int j = 0; j < 2; ++j) {
// 				int	temp_cnt = 0;
// 				while (temp_iter[j][i] != house[j].type[i].end()) {
// 					if (temp_iter[j][i]->first < perform_min->first) {
// 						if (temp_cnt != 0)
// 							--temp_iter[j][i];
// 						break ;
// 					}
// 					if (temp_iter[j][i]->second < price_min->second)
// 						price_min = temp_iter[j][i];
// 					++temp_iter[j][i];
// 					++temp_cnt;
// 				}
// 			}
// 			cur_iter[i] = price_min;
// 			res.mPrice += cur_iter[i]->second;
// 		}
// 		// for (int i = 0; i < 3; ++i)
// 		// 	printf("type_%d) Perform : %d Price : %d\n", i, cur_iter[i]->first, cur_iter[i]->second);
// 		// usleep(100 * 1000);
// 		// printf("total) Perform : %d Price : %d Budget : %d\n\n", res.mPerformance, res.mPrice, budget);

// 		if (res.mPrice <= budget)
// 			return (res);

// 		max_idx = -1;
// 		for (int i = 0; i < 3; ++i) {
// 			check = 0;
// 			for (int j = 0; j < 2; ++j) {
// 				// if (i == 0)
// 				// 	printf("temp[%d] perform = %d\n", j, temp_iter[j][i]->first);
// 				temp_next[j][i] = temp_iter[j][i];
// 				while (temp_next[j][i] != house[j].type[i].end()) {
// 					if (temp_next[j][i]->second < cur_iter[i]->second)
// 						break ;
// 					else
// 						++temp_next[j][i];
// 				}
// 				// if (i == 0)
// 				// 	printf("temp_next[%d] perform = %d\n", j, temp_next[j][i]->first);
// 				if (temp_next[j][i] == house[j].type[i].end())
// 					check += j + 1;
// 			}
// 			// printf("check = %d\n", check);
// 			if (check == 3)
// 				continue ;
// 			else if (check == 0) {
// 				if (temp_next[0][i]->first > temp_next[1][i]->first) {
// 					next_iter[i] = temp_next[0][i];
// 					temp_ware = 0;
// 				}
// 				else if (temp_next[0][i]->first == temp_next[1][i]->first) {
// 					if (temp_next[0][i]->second < temp_next[1][i]->second) {
// 						next_iter[i] = temp_next[0][i];
// 						temp_ware = 0;
// 					}
// 					else {
// 						next_iter[i] = temp_next[1][i];
// 						temp_ware = 1;
// 					}
// 				}
// 				else {
// 					next_iter[i] = temp_next[1][i];
// 					temp_ware = 1;
// 				}
// 				// printf("p0 = %d, p1 = %d\n",temp_next[0][i]->first, temp_next[1][i]->first);
// 			}
// 			else if (check == 1){
// 				next_iter[i] = temp_next[1][i];
// 				temp_ware = 1;
// 			}
// 			else if (check == 2){
// 				next_iter[i] = temp_next[0][i];
// 				temp_ware = 0;
// 			}
// 			// if (max_idx != -1)
// 			// 	printf("max perform = %d, cur_perform = %d\n",next_iter[max_idx]->first, next_iter[i]->first);
// 			if (max_idx == -1) {
// 				max_idx = i;
// 				max_ware = temp_ware;
// 			}
// 			else if (next_iter[i]->first > next_iter[max_idx]->first) {
// 				max_idx = i;
// 				max_ware = temp_ware;
// 			}
// 		}
// 		if (max_idx == -1) {
// 			res.mPerformance = 0;
// 			res.mPrice = 0;
// 			return (res);
// 		}
// 		else {
// 			// printf("max_idx = %d, max_ware = %d\n", max_idx, max_ware);
// 			cur_iter[max_idx] = next_iter[max_idx];
// 			temp_iter[max_ware][max_idx] = next_iter[max_idx];
// 			perform_min = next_iter[max_idx];
// 		}
// 	}
// }