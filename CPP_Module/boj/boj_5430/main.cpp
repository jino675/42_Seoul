#include <iostream>
#include <deque>

using namespace std;

int		R_flag;
int 	T;
char	P[100001];
char	dummy;
int		N;
int		val;
deque<int>	arr;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; ++i) {
		R_flag = 0;
		cin >> P >> N >> dummy;
		if (N == 0)
			cin >> dummy;
		for (int j = 0; j < N; ++j) {
			cin >> val >> dummy;
			arr.push_back(val);
		}
		for (int j = 0; P[j] != '\0'; ++j) {
			if (P[j] == 'R')
				++R_flag;
			else if (P[j] == 'D') {
				if (arr.empty() == true) {
					cout << "error\n";
					R_flag = -1;
					break ;
				}
				if (R_flag % 2 == 0)
					arr.pop_front();
				else
					arr.pop_back();
			}
		}
		if (R_flag != -1) {
			cout << "[";
			if (arr.empty() == true)
				cout << "]\n";
			while (arr.empty() != true) {
				if (R_flag % 2 == 0) {
					cout << arr.front();
					arr.pop_front();
				}
				else {
					cout << arr.back();
					arr.pop_back();
				}
				if (arr.size() > 0)
					cout << ",";
				else
					cout << "]\n";
			}
		}
	}
}