#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<pair<int, long long>>> info;
vector<long long> dist_fox;
vector<vector<long long>> dist_wolf;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;

	info.assign(n + 1, vector<pair<int, long long>>());
	dist_fox.assign(n + 1, LLONG_MAX);
	dist_wolf.assign(n + 1, vector<long long>(2,LLONG_MAX));

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		info[a].push_back({ b,c*2 });
		info[b].push_back({a,c*2});
	}

	priority_queue<pair<long long, int>> pqf;			// 여우 이동
	pqf.push({ 0,1 });
	dist_fox[1] = 0;

	while (!pqf.empty()) {
		long long cost = -pqf.top().first;
		int pos = pqf.top().second;
		pqf.pop();

		if (cost > dist_fox[pos])
			continue;

		for (auto a : info[pos]) {
			if (dist_fox[a.first] > dist_fox[pos] + a.second) {
				dist_fox[a.first] = dist_fox[pos] + a.second;
				pqf.push({ -dist_fox[a.first], a.first });
			}
		}
	}

	priority_queue<pair<long long, pair<int, int>>> pqw;		// 늑대 이동
	pqw.push({ 0, {1,1} });
	dist_wolf[1][0] = 0;
	while (!pqw.empty()) {
		long long cost = -pqw.top().first;
		int pos = pqw.top().second.first;
		int flag = pqw.top().second.second;
		pqw.pop();

		if (flag==1) {
			if (cost > dist_wolf[pos][0])
				continue;
			for (auto a : info[pos]) {
				if (dist_wolf[a.first][1] > dist_wolf[pos][0] + a.second / 2) {
					dist_wolf[a.first][1] = dist_wolf[pos][0] + a.second / 2;
					pqw.push({ -dist_wolf[a.first][1],{a.first,0} });
				}
			}
		}
		else {
			for (auto a : info[pos]) {
				if (cost > dist_wolf[pos][1])
					continue;
				if (dist_wolf[a.first][0] > dist_wolf[pos][1] + a.second * 2) {
					dist_wolf[a.first][0] = dist_wolf[pos][1] + a.second * 2;
					pqw.push({ -dist_wolf[a.first][0],{a.first,1} });
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		if (dist_fox[i] < min(dist_wolf[i][0], dist_wolf[i][1]))
			++cnt;
	}

	cout << cnt;
	return 0;
}

