#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

struct schedule{
	int s;
	int t;
};

bool MyCompare(const schedule &x,const schedule &y){
	if (x.s < y.s)
		return (true);
	else
		return (false);
}

int	max_val;
int N;
priority_queue<int, vector<int>, greater<int> > pq;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	schedule input;
	vector<schedule> v;
	
	cin >> N;
	for (int i = 0 ; i < N ; ++i) {
		cin >> input.s >> input.t; 
		v.push_back(input);
	}
	sort(v.begin(), v.end(), MyCompare);

	for (int i = 0 ; i < N ; ++i) {
		pq.push(v[i].t);
		while (pq.top() <= v[i].s)
			pq.pop();
		if (pq.size() > max_val)
			max_val = pq.size();
	}
	cout << max_val << "\n";

	return (0);
}