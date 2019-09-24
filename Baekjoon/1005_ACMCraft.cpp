#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 위상정렬

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, k;
		cin >> n >> k;

		vector<int> degree(n + 1, 0);
		vector<int> time(n + 1);
		vector<vector<int>> info(n + 1);
		vector<int> dp(n + 1);

		for (int i = 1; i <= n; ++i) {
			cin >> time[i];
			dp[i] = time[i];
		}

		for (int i = 1; i <= k; ++i) {
			int a, b;
			cin >> a >> b;
			info[a].push_back(b);
			++degree[b];
		}

		int w;
		cin >> w;

		priority_queue<pair<int, int>> q;
		for (int i = 1; i <= n; ++i){
			if (degree[i] == 0)
				q.push({ time[i],i });
		}

		int ans = 0;
		while (!q.empty()) {
			int d = q.top().second;
			ans = q.top().first;
			q.pop();

			vector<pair<int, int>> temp;
			while (!q.empty()) {
				temp.push_back(q.top());
				q.pop();
			}
			for (auto a : temp) {
				int nd = a.second;

				for (auto b : info[nd]) {
					--degree[b];
					dp[b] = max(dp[b], dp[nd] + time[b]);
					if(degree[b] == 0)
						q.push({ dp[b],b });
				}
			}

			if (d == w)
				break;

			for (auto a : info[d]) {
				--degree[a];
				dp[a] = max(dp[a], ans + time[a]);		// 값을 갱신
				if (degree[a] == 0)
					q.push({ dp[a],a });
			}
		}

		cout << dp[w] << "\n";
	}

	return 0;
}