#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

// 크루스칼 x 다익스트라 o
vector<vector<pair<int, int>>> info;
priority_queue<pair<int, pair<int, int>>> pq;
vector<pair<int, int>> answer;
vector<int> dist;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	dist.assign(n + 1, INT_MAX);
	info.assign(n+1, vector<pair<int, int>>());

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		info[a].push_back({b,c});
		info[b].push_back({a,c});
	}
	
	pq.push({ 0, {1,0} });		// 비용, {목적지, 출발지}
	while (!pq.empty()) {
		int pos = pq.top().second.first;
		int prev = pq.top().second.second;
		int cost = -pq.top().first;
		pq.pop();

		if (dist[pos] != INT_MAX)
			continue;
		dist[pos] = cost;
		
		if (prev > 0)
			answer.push_back({pos,prev});
		for (auto a : info[pos]) {
			int next = a.first;
			if (dist[next] != INT_MAX)
				continue;
			pq.push({ -cost - a.second, {next, pos} });
		}
	}

	cout << answer.size() << "\n";
	for (auto a : answer)
		cout << a.first << " " << a.second << "\n";

	return 0;
}