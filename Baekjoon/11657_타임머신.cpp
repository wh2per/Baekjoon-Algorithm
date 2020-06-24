#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// 벨만 포드

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, long long>>> info(n + 1, vector<pair<int, long long>>());

	for (int i = 0; i < m; ++i) {
		int a, b;
		long long c;
		cin >> a >> b >> c;

		info[b].push_back({ a,c });		// 반대로! (나에게로 올 수 있는 정점, 그 때 비용)
	}

	vector<long long> dist(n + 1, LLONG_MAX);
	dist[1] = 0;		// 시작점 초기화

	for (int i = 1; i < n; ++i) {				// 사용할 간선 n-1만큼 돌려보기
		for (int j = 1; j <= n; ++j) {			// 정점 1~N까지 돌려보기
			for (int k = 0; k < info[j].size(); ++k) {		// 정점에서 갈 수 있는 곳
				if (dist[info[j][k].first] == LLONG_MAX)		// 출발점이 아직 갱신된 곳이 아니라면 스킵
					continue;
				if (dist[j] > dist[info[j][k].first] + info[j][k].second) {		 // 값이 갱신 될때 
					dist[j] = dist[info[j][k].first] + info[j][k].second;
				}
			}
		}
	}

	// 음수 사이클이 있는 지 검사
	bool flag = false;
	for (int j = 1; j <= n; ++j) {			// 정점 1~N까지 돌려보기
		for (int k = 0; k < info[j].size(); ++k) {		// 정점에서 갈 수 있는 곳
			if (dist[info[j][k].first] == LLONG_MAX)		// 출발점이 아직 갱신된 곳이 아니라면 스킵
				continue;
			if (dist[j] > dist[info[j][k].first] + info[j][k].second) {		 // 값이 갱신 될때 
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}

	if (flag)
		cout << -1 << "\n";
	else {
		for (int i = 2; i <= n; ++i) {
			if (dist[i] == LLONG_MAX)
				dist[i] = -1;
			cout << dist[i] << "\n";
		}
	}
	return 0;
}