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

	int n, m;
	cin >> n >> m;

	vector<vector<int>> info(n + 1, vector<int>());
	vector<int> dist(n + 1, INT_MAX);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		info[a].push_back(b);
		info[b].push_back(a);
	}

	vector<int> ans;
	dist[1] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0,1});
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		for (auto a : info[pos]) {
			if (dist[a] > dist[pos] + 1) {
				dist[a] = dist[pos] + 1;
				pq.push({-dist[a], a});
			}
		}
	}

	int ans_dist = *max_element(dist.begin()+1, dist.end());
	for (int i = 1; i <= n; ++i) {
		if (dist[i] == ans_dist)
			ans.push_back(i);
	}

	cout << ans[0] << " " << ans_dist << " " << ans.size();

	return 0;
}