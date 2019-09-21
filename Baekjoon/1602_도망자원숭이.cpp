#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

// 플로이드 와샬

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, q;
	cin >> n >> m >> q;

	vector<pair<int, int>> dog;
	vector<int> times(n+1);

	for (int i = 1; i <= n; ++i) {
		cin >> times[i];
		dog.push_back({ times[i],i });
	}
	sort(dog.begin(), dog.end());

	vector<vector<int>> info(n + 1, vector<int>(n + 1, 1e9));
	vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= m; ++i) {
		int a, b, d;
		cin >> a >> b >> d;
		info[a][b] = d;
		info[b][a] = d;
	}

	for (int i = 1; i <= n; ++i)
		info[i][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)
				ans[i][j] = info[i][j] + max(dog[i - 1].first, dog[j - 1].first);
		}
	}

	for (int e = 0; e < dog.size(); ++e) {
		int w = dog[e].second;			// 경유
		int cost = dog[e].first;

		for (int j = 1; j <= n; ++j) {		// 시작점
			for (int k = 1; k <= n; ++k) { 	// 도착점
				info[j][k] = min(info[j][k], info[j][w] + info[w][k]);
				ans[j][k] = max(info[j][k] + max(times[j], times[k]), min(ans[j][k],info[j][w] + info[w][k] + cost));
			}
		}
	}

	for (int i = 1; i <= q; ++i) {
		int s, t;
		cin >> s >> t;

		if (ans[s][t] >= 1e9)
			cout << -1 << "\n";
		else
			cout << ans[s][t] << "\n";
	}

	return 0;
}