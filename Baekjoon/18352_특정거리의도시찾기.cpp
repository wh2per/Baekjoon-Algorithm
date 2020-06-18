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

	int n, m, k, x;
	cin >> n >> m >> k >> x;

	vector<vector<int>> info(n + 1, vector<int>());
	vector<int> dist(n + 1, INT_MAX);


	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		info[a].push_back(b);
	}

	dist[x] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,x });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		for (auto a : info[pos]) {
			if (dist[a] > dist[pos] + 1) {
				dist[a] = dist[pos] + 1;
				pq.push({ -dist[a], a });
			}
		}
	}

	bool flag = false;
	for (int i = 1; i <= n; ++i) {
		if (dist[i] == k) {
			cout << i << "\n";
			flag = true;
		}
	}

	if (!flag)
		cout << -1;
	return 0;
}