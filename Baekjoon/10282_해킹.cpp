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

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, d, c;
		cin >> n >> d >> c;

		vector<vector<pair<int, int >>> info(n+1,vector<pair<int, int>>());
		vector<int> dist(n+1, INT_MAX);
		for (int i = 0; i < d; ++i) {
			int a, b, s;
			cin >> a >> b >> s;

			info[b].push_back({ a,s });
		}

		dist[c] = 0;
		priority_queue<pair<int, int>> pq;
		pq.push({0,c});
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int pos = pq.top().second;
			pq.pop();

			for (auto a : info[pos]) {
				if (dist[a.first] > dist[pos] + a.second) {
					dist[a.first] = dist[pos] + a.second;
					pq.push({-dist[a.first], a.first});
				}
			}
		}

		int ans_time = INT_MIN;
		int ans_cnt=0;
		for (int i = 1; i <= n; ++i) {
			if (dist[i] != INT_MAX) {
				++ans_cnt;
				ans_time = max(ans_time, dist[i]);
			}
		}
		cout << ans_cnt << " " << ans_time << "\n";
	}
	return 0;
}