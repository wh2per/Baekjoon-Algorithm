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

			info[v].push_back({ u,-c });	// 반대로 저장!
		}

		vector<int> dist(n + 1, INT_MAX);
		dist[1] = 0;
		bool flag = false;

		for (int i = 1; i <= n; ++i) {				// 간선은 다 사용할 필요없이 n-1보다만 많이 사용하면 됨	
			for (int j = 1; j <= n; ++j) {			// 정점 1~N까지 돌려보기
				for (int k = 0; k < info[j].size(); ++k) {		// 정점에서 갈 수 있는 곳
					if (dist[info[j][k].first] == INT_MAX)		// 출발점이 아직 갱신된 곳이 아니라면 스킵
						continue;
					if (dist[j] > dist[info[j][k].first] + info[j][k].second) {		 // 값이 갱신 될때 
						dist[j] = dist[info[j][k].first] + info[j][k].second;
						if (i == n) {
							flag = true;
							break;
						}
					}
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}

		if (flag)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}