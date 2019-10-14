#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<pair<int, int>>> info(n+1, vector<pair<int,int>>());
	vector<int> dist(n+1, INT_MAX);

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		info[a].push_back({b,c});
	}

	int s, e;
	cin >> s >> e;

	dist[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0,s});

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		
		if (cost > dist[e])
			continue;

		for (auto a : info[pos]) {
			int next = a.first;
			int ncost = a.second;

			if (dist[next] > dist[pos] + ncost) {
				dist[next] = dist[pos] + ncost;
				pq.push({-dist[next], next});
			}
		}
	}

	cout << dist[e];
	return 0;
}