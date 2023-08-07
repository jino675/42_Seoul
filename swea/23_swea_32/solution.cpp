/*
No. 32 연락처 DataBase
참여자 49 제출 215 배점 100
Problem제출이력정답
시간 : 0개 테스트케이스를 합쳐서 C/C++의 경우 5초 / Java의 경우 5초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

- 코드배틀 비밀번호 및 게시된 문제의 타인 공유 / 무단 복제는 엄격히 금지됩니다.
- 지원언어 : C++ / JAVA
* STL 라이브러리 사용 가능

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

 


[문제 설명]

연락처 App에 사용되는 DataBase를 만들려고 한다.

연락처 DataBase에 [Table 1]와 같이 3명의 정보가 저장되어 있다고 생각해보자.

연락처 정보의 각 항목을 field라 하고, 5개의 field가 모인 한 사람의 정보를 record라고 한다.



연락처 DataBase에서는 [Table 2] 와 같이 5개의 field가 사용된다.



 

연락처 DataBase가 제공해야 하는 5개의 API를 작성하라.

 

void InitDB ()

Database를 초기화한다.

void Add (char* name, char* number, char* birthday, char* email, char* memo)

Database에 한 개의 record를 추가한다

record는 name, number, birthday, email, memo 5개의 field로 되어있다.

Parameters:

name: NAME field 값
number: NUMBER field 값
birthday: BIRTHDAY field 값
email: EMAIL field 값
memo: MEMO field 값

int Delete (FIELD field, char* str)

field값이 str인 record를 삭제한다.

 

Parameters:

field: field 정보
str: 삭제하려는 record의 field 값

 

Returns:

int: 삭제한 record 의 개수. 삭제한 record 가 없으면 0

int Change (FIELD field, char* str, FIELD changefield, char* chagestr)

field값이 str인 record를 찾고, 해당 record의 changefield 값을 chagnestr로 변경한다.

 

Parameters:

field: field 정보
str: record의 field 값
changefield: 변경해야 하는 field 정보
changestr: 변경해야하는 record의 field 값

 

Returns:

int: 변경한record 의 개수. 변경한 record 가 없으면 0

RESULT Search (FIELD field, char* str, FIELD returnfield)

field값이 str인 record를 찾고 record 개수와 record의 returnfield 값을 반환한다.

 

Parameters:

field: field 정보
str: record의 field 값
returfield: 반환해야하는 field 정보

 

Returns:

count: field값이 str인 record의 개수

str: 해당 record의 returnfield 값, count 값이 0이거나 2이상인 경우 str은 무시된다.

 

 

[예시]

아래 코드는 예시를 위한 값으로 실제 입력 데이터와 다를 수 있다.

입력

결과

Add(“A”, “111”, “0101”, “a.com”, “aaa”);

 
Add(“B”, “222”, “0202”, “b.com”, “bbb”);

 
Add(“C”, “333”, “0303”, “c.com”, “ccc”);

 
Add(“D”, “444”, “0505”, “d.com”, “ddd”);

 
Add(“E”, “555”, “0505”, “e.com”, “eee”);

 
result = Search(NAME, “A”, EMAIL);

result.count = 1;

result.str = “a.com”;

Change(NAME, “A”, EMAIL, “d.com”);

result = 1;

result = Search(NAME, “A”, EMAIL);

result.count = 1;

result.str = “d.com”;

Delete(NUMBER, “777”);

result = 0;

result = Search(BIRTHDAY, “0505”, MEMO);

result.count = 2;

result.str = “”; // result.str 값은 무시된다.

Delete(EMAIL, “d.com”);

result = 2;

result = Search(NAME, “A”, EMAIL);

result.count = 0;

result.str = “”; // result.str 값은 무시된다.

Change(BIRTHDAY, “0505”, MEMO, “zzz”);

result = 2;

result = Search(NAME, “E”, MEMO);

result.count = 1;

result.str = “zzz”;

 


[제약 사항]

1. 각 test case 의 최대 record 개수는 50,000개 이하이다.

2. 각 test case 시작 시에 InitDB() 함수가 호출된다.

3. 입력으로 주어지는 각 field 값은 make_field() 함수에서 만들어지는 field와 동일한 포맷으로 만들어진다.

4. Delete(), Change(), Search() 함수의 경우, field값이 str인 record 개수가 여러 개 일수 있다.

 

[입력 / 출력]

입출력은 제공되는 Main 부분의 코드에서 처리함으로 User Code 부분의 코드에서는 별도로 입출력 함수를 사용해서는 안 된다.

출력 결과는 아래와 같은 형태로 보여진다. (출력 값은 예시이며, 실제 출력 값과 동일하지 않을 수 있다.)

#1 1000

#2 1000

#3 1000

#4 1000

#5 1000

TotalScore = 5000
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

typedef enum
{
	NAME,
	NUMBER,
	BIRTHDAY,
	EMAIL,
	MEMO
} FIELD;

typedef struct s_node
{
	string	s[5];
}	t_node;

t_node	data[50000];
int		data_count;

unordered_multimap<string, int>	table[5];

typedef struct
{
	int count;
	char str[20];
} RESULT;

void InitDB()
{
	table[NAME].clear();
	table[NUMBER].clear();
	table[BIRTHDAY].clear();
	table[EMAIL].clear();
	table[MEMO].clear();
	data_count = 0;
}

void Add(char* name, char* number, char* birthday, char* email, char* memo)
{
	data[data_count].s[NAME] = name;
	data[data_count].s[NUMBER] = number;
	data[data_count].s[BIRTHDAY] = birthday;
	data[data_count].s[EMAIL] = email;
	data[data_count].s[MEMO] = memo;
	table[NAME].insert(make_pair(data[data_count].s[NAME], data_count));
	table[NUMBER].insert(make_pair(data[data_count].s[NUMBER], data_count));
	table[BIRTHDAY].insert(make_pair(data[data_count].s[BIRTHDAY], data_count));
	table[EMAIL].insert(make_pair(data[data_count].s[EMAIL], data_count));
	table[MEMO].insert(make_pair(data[data_count].s[MEMO], data_count));
	++data_count;

	// int idx = data_count - 1;
	// printf("[add] idx : %d, name : %s, number : %s, birthday : %s, email : %s, memo : %s\n",\
	// 		idx, data[idx].s[0].c_str(), data[idx].s[1].c_str(), data[idx].s[2].c_str(), \
	// 										data[idx].s[3].c_str(), data[idx].s[4].c_str());
}

int Delete(FIELD field, char* str)
{
	int		idx;
	int		count;
	string	key;
	
	count = 0;
	key = str;
	auto	range = table[field].equal_range(key);
	auto	iter = range.first;
	while (iter != range.second) {
		idx = iter->second;
		for (int i = 0; i < 5; ++i) {
			if (i == field)
				continue ;
			auto	temp_range = table[i].equal_range(data[idx].s[i]);
			for (auto temp_iter = temp_range.first; temp_iter != temp_range.second; ++temp_iter) {
				if (temp_iter->second == idx) {
					table[i].erase(temp_iter);
					break ;
				}
			}
		}
		iter = table[field].erase(iter);
		++count;
	}
	return (count);
}

int Change(FIELD field, char* str, FIELD changefield, char* changestr)
{
	int		idx;
	int		count;
	string	key;

	key = str;
	count = 0;
	auto	range = table[field].equal_range(key);
	auto	iter = range.first;
	while (iter != range.second) {
		idx = iter->second;

		// printf("[before] idx : %d, name : %s, number : %s, birthday : %s, email : %s, memo : %s\n",\
		// 		idx, data[idx].s[0].c_str(), data[idx].s[1].c_str(), data[idx].s[2].c_str(), \
		// 										data[idx].s[3].c_str(), data[idx].s[4].c_str());

		if (field != changefield) {
			auto temp_range = table[changefield].equal_range(data[idx].s[changefield]);
			auto temp_iter = temp_range.first;
			while (temp_iter != temp_range.second) {
				if (temp_iter->second == idx) {
					table[changefield].erase(temp_iter);
					data[idx].s[changefield] = changestr;
					table[changefield].insert(make_pair(data[idx].s[changefield], idx));
					break ;
				}
				++temp_iter;
			}
			++iter;
		}
		else {
			data[idx].s[field] = changestr;
			iter = table[field].erase(iter);
			table[field].insert(make_pair(data[idx].s[field], idx));
		}	

		// printf("[after] idx : %d, name : %s, number : %s, birthday : %s, email : %s, memo : %s\n",\
		// 		idx, data[idx].s[0].c_str(), data[idx].s[1].c_str(), data[idx].s[2].c_str(), \
		// 										data[idx].s[3].c_str(), data[idx].s[4].c_str());
		++count;
	}
	return (count);
}

RESULT Search(FIELD field, char* str, FIELD ret_field)
{
	int		idx;
	string	key;
	RESULT result;

	key = str;
	result.count = table[field].count(key);
	if (result.count == 1) {
		auto	iter = table[field].find(key);
		idx = iter->second;
		strcpy(result.str, data[idx].s[ret_field].c_str());
		// printf("\n\nlen = %ld, %s\n", data[idx].s[ret_field].length(), data[idx].s[ret_field].c_str());
	}
	return result;
}