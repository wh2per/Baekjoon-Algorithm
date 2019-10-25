#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
using namespace std;

vector<vector<pair<int, int>>> info;
vector<vector<int>> dist;
vector<bool> check;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;

	info.assign(n + 1, vector<pair<int, int>>());
	dist.assign(n + 1, vector<int>(2, INT_MAX));
	check.assign(n + 1, false);

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;

		info[u].push_back({ v,-w });
	}

	dist[1][0] = 0;
	dist[1][1] = 0;

	for (int i = 1; i <= n; ++i) {				// 간선은 다 사용할 필요없이 n-1보다만 많이 사용하면 됨	
		for (int j = 1; j <= n; ++j) {			// 정점 1~N까지 돌려보기
			for (int k = 0; k < info[j].size(); ++k) {		// 정점에서 갈 수 있는 곳
				if (dist[j][0] == INT_MAX)		// 출발점이 아직 갱신된 곳이 아니라면 스킵
					continue;
				if (dist[info[j][k].first][0] > dist[j][0] + info[j][k].second) {		 // 값이 갱신 될때 
					dist[info[j][k].first][0] = dist[j][0] + info[j][k].second;
					dist[info[j][k].first][1] = j;
					if (i == n) {
						check[j] = true;
						q.push(j);
					}
				}
			}
		}
	}

	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		for (int k = 0; k < info[pos].size(); ++k) {
			if (!check[info[pos][k].first]) {
				check[info[pos][k].first] = true;
				q.push(info[pos][k].first);
			}
		}
	}

	if (dist[n][0] == INT_MAX || check[n])
		cout << -1;
	else {
		stack<int> path;
		int end = n;

		while (end != 0) {
			path.push(end);
			end = dist[end][1];
		}

		while (!path.empty()) {
			cout << path.top() << " ";
			path.pop();
		}
	}

	return 0;
}