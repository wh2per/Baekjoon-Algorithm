#include <iostream>
#include <climits>
#include <queue>
using namespace std;

// 다익스트라

vector<pair<int, int>> info[20001];
int dist[20001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int v, e,k;
	cin >> v >> e;
	cin >> k; 

	for (int i = 0; i < e; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		
		info[u].push_back({v,w});
	}

	fill(dist, dist + v + 1, INT_MAX);
	priority_queue<pair<int, int>> q;

	q.push({ 0, k });	// 시작점 추가
	dist[k] = 0;		// 시작점 최단거리

	while (!q.empty()) {
		int cost = q.top().first;		// 현재 비용
		int pos = q.top().second;		// 현재 위치

		q.pop();

		for (int i = 0; i < info[pos].size(); ++i) {		// 나와 연결되어있는 곳 순회
			int next = info[pos][i].first;
			int ncost = info[pos][i].second;

			if (dist[next] > dist[pos] + ncost) {		// 거리를 갱신해야 할 경우
				dist[next] = dist[pos] + ncost;
				q.push({-dist[next], next});			// 계속 진행하기 위해 큐에 삽입
			}
		}
	}

	for (int i = 1; i <= v; ++i) {
		if (i == k)
			cout << 0 << "\n";
		else {
			if (dist[i] == INT_MAX)
				cout << "INF" << "\n";
			else
				cout << dist[i] << "\n"
		}
	}

	return 0;
}