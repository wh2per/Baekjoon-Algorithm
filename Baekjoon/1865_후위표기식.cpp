#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// 벨만포드

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int n, m, w;
		cin >> n >> m >> w;

		vector<vector<pair<int, int>>> info(n + 1, vector<pair<int, int>>());

		for (int i = 0; i < m; ++i) {		// 일반 양방향
			int u, v, c;
			cin >> u >> v >> c;

			info[u].push_back({ v,c });
			info[v].push_back({ u,c });
		}

		for (int i = 0; i < w; ++i) {		// 웜홀 단방향
			int u, v, c;
			cin >> u >> v >> c;

			info[u].push_back({ v,-c });
		}

		vector<int> dist(n + 1, 987654321);
		bool flag = false;
		dist[0] = dist[1] = 0;

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int k = 0; k < info[j].size(); ++k) {
					int to = info[j][k].first;
					int cost = info[j][k].second;

					if (dist[to] > dist[j] + cost) {
						dist[to] = dist[j] + cost;
						if (i == n)
							flag = true;
					}
				}
			}
		}
		if (flag)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}