#include <iostream>
#include <time.h>

using namespace std;

#define VAL_MAX 101

int main(void)
{
	int	tc;
	int	N, Q;
	int	a_i, cmd, idx, x, l, r;

	// srand((unsigned int)time(NULL));
	tc = 1;
	for (int i = 0; i < tc; ++i) {
		N = 10;
		Q = 20;
		cout << tc << " " << N << " " << Q;
		for (int j = 0; j < N; ++j) {
			a_i = rand() % VAL_MAX;
			cout << " " << a_i; 
		}
		for (int j = 0; j < Q; ++j) {
			cmd = rand() % 2;
			cout << " " << cmd;
			if (cmd == 0) {
				idx = rand() % N;
				x = rand() % VAL_MAX;
				cout << " " << idx << " " << x;
			}
			else if (cmd == 1) {
				l = rand() % N;
				r = rand() % (N - l) + 1 + l;
				cout << " " << l << " " << r;
			}
		}
		cout << "\n";
	}
	return (0);
}