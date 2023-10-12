/*
최단경로
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	182341	54407	27620	25.274%
문제
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.

입력
첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1 ≤ V ≤ 20,000, 1 ≤ E ≤ 300,000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다. 둘째 줄에는 시작 정점의 번호 K(1 ≤ K ≤ V)가 주어진다. 셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다. 이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. u와 v는 서로 다르며 w는 10 이하의 자연수이다. 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.

출력
첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다. 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.

예제 입력 1 
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
예제 출력 1 
0
2
3
7
INF
*/
#include <iostream>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

unordered_map<int, int>	vertex[20001];
int	visited[20001];
int	cost[20001];

int	V, E;
int	start;
int	u, v, w;
int	cur, cnt;

struct my_compare {
	bool	operator()(const pair<int, int> &a, const pair<int, int> &b) const {
		return (a.second > b.second);
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, my_compare>	pq;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E >> start;
	for (int i = 0; i < E; ++i) {
		cin >> u >> v >> w;
		if (vertex[u].find(v) == vertex[u].end() || vertex[u][v] > w)
			vertex[u][v] = w;
	}
	for (int i = 1; i <= V; ++i)
		cost[i] = INT_MAX;
	cost[start] = 0;
	pq.push({start, 0});
	while (pq.empty() == false) {
		cur = pq.top().first;
		pq.pop();
		if (visited[cur] == 0) {
			visited[cur] = 1;
			for (auto it = vertex[cur].begin(); it != vertex[cur].end(); ++it) {
				if (visited[it->first] == 0 && cost[it->first] > cost[cur] + it->second) {
					cost[it->first] = cost[cur] + it->second;
					pq.push({it->first, cost[it->first]});
				}
			}
			++cnt;
			if (cnt == V)
				break ;
		}
	}
	for (int i = 1; i <= V; ++i) {
		if (cost[i] == INT_MAX)
			cout << "INF" << "\n";
		else
			cout << cost[i] << "\n";
	}
}