#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

// 다익스트라

struct node {
	int pos;
	int cost;
	int time;
};

struct cmp {				// top에 가장 작은 수가 가도록 비용을 내림차순 정렬
	bool operator()(node t, node u) {
		if (t.time > u.time)
			return true;
		else
			return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<vector<node>> info(n+1, vector<node>());

		for (int i = 0; i < k; ++i) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;

			info[u].push_back({ v,c,d });		// dist, {cost, time}
		}

		priority_queue<node, vector<node>, cmp> pq; 
		vector<vector<int>> dist(n + 1,vector<int>(10001,-1));
		pq.push({ 1,0,0 });		// 위치 비용 시간
		dist[1][0] = 0;		// 시작점 초기화

		while (!pq.empty()) {
			node curr = pq.top();
			pq.pop();
			
			if (curr.time > dist[curr.pos][curr.cost] || curr.cost > m)
				continue;

			for (int i = 0; i < info[curr.pos].size(); ++i) {
				node next = info[curr.pos][i];
				int ncost = next.cost + curr.cost;
				if (ncost > m)
					continue;

				if ((dist[next.pos][ncost] == -1 || dist[next.pos][ncost] > curr.time + next.time) && curr.cost + next.cost <=m) {		// 거리를 갱신해야 할 경우
					dist[next.pos][ncost] = curr.time + next.time;
					pq.push({next.pos, ncost, curr.time + next.time});
				}
			}
		}
		int ans = INT_MAX;
		for (int i = 0; i <= m; ++i) {
			if (dist[n][i] != -1 && ans > dist[n][i])
				ans = dist[n][i];
		}

		if (ans == INT_MAX)
			cout << "Poor KCM\n";
		else
			cout << ans << "\n";
	}
	

	return 0;
}