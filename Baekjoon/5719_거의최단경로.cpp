#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <string.h>
#include <cstring>
using namespace std;

// 다익스트라

vector<pair<int, int>> info[501];
int dist[501];
vector<int> path[501];
bool check[501];

void dfs(int start, int end) {
	for (int i = 0; i < info[start].size(); ++i) {
		if (info[start][i].first == end) {
			if (info[start][i].second == -1)
				continue;
			info[start][i].second = -1;
			for (auto b : path[start])
				dfs(b, start);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("sample_input.txt", "r", stdin);

	while (1) {
		int n, m, s, d;
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		cin >> s >> d;

		for (int i = 0; i < 501; ++i) {		// info,path 초기화
			info[i].clear();
			path[i].clear();
		}
		fill(dist, dist + n, INT_MAX);

		for (int i = 0; i < m; ++i) {
			int u, v, p;
			cin >> u >> v >> p;
			info[u].push_back({ v,p });
		}

		priority_queue<pair<int, int>> q;

		dist[s] = 0;
		q.push({ 0,s });

		while (!q.empty()) {
			int cost = -q.top().first;
			int pos = q.top().second;
			q.pop();

			if (cost > dist[d])		// 비용 초과했을 경우 스킵
				continue;

			for (auto a : info[pos]) {
				int next = a.first;
				int ncost = a.second;

				if (dist[next] > dist[pos] + ncost) {		// 거리를 갱신해야 할 경우
					dist[next] = dist[pos] + ncost;
					q.push({ -dist[next],next });

					path[next].clear();
					path[next].push_back(pos);
				}
				else if (dist[next] == dist[pos] + ncost) 		// path를 추가하자
					path[next].push_back(pos);
			}
		}

		memset(check, false, sizeof(check));
		for (auto a : path[d])
			dfs(a, d);

		fill(dist, dist + n, INT_MAX);
		priority_queue<pair<int, int>> nq;

		dist[s] = 0;
		nq.push({ 0,s });
		while (!nq.empty()) {
			int cost = -nq.top().first;
			int pos = nq.top().second;
			nq.pop();

			if (pos == d)
				break;

			if (cost > dist[d])
				continue;

			for (auto a : info[pos]) {
				if (a.second == -1)
					continue;
				int ncost = a.second;
				int next = a.first;

				if (dist[next] > dist[pos] + ncost) {
					dist[next] = dist[pos] + ncost;
					nq.push({ -dist[next], next });
				}
			}
		}

		if (dist[d] == INT_MAX)
			cout << "-1\n";
		else
			cout << dist[d] << "\n";
	}

	return 0;
}