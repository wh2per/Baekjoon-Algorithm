#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 플로이드 와샬

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;

	vector<vector<int>> info(v + 1, vector<int>(v + 1, INT_MAX));

	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		info[a][b] = c;
	}

	for (int i = 1; i <= v; ++i)
		info[i][i] = 0;

	for (int i = 1; i <= v; ++i) {		// 경유
		for (int j = 1; j <= v; ++j) {	// 시작점
			if (info[j][i] == INT_MAX)
				continue;
			for (int k = 1; k <= v; ++k) { 	// 도착점
				if (info[i][k] == INT_MAX)
					continue;
				if (info[j][k] > info[j][i] + info[i][k])		// 시작-도착 길이 없거나 경유하는 것보다 클때
					info[j][k] = info[j][i] + info[i][k];
			}
		}
	}
	int ans = INT_MAX;

	for (int i = 1; i <= v; ++i) {
		for (int j = 1; j <= v; ++j) {
			if (i==j || info[i][j] == INT_MAX || info[j][i] == INT_MAX)
				continue;
			ans = min(ans, info[i][j] + info[j][i]);
		}
	}
	if (ans == INT_MAX)
		cout << -1;
	else
		cout << ans;

	return 0;
}