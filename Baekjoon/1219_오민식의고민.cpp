#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <string.h>
#include <cstring>
using namespace std;

vector<pair<int, int>> info[101];
long long money[101];
long long ans[101];
bool gees[101];

bool check[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("sample_input.txt", "r", stdin);

	int n, s, e, m;
	cin >> n >> s >> e >> m;

	while (m--) {
		int start, end, cost;
		cin >> start >> end >> cost;

		info[start].push_back({ end,cost });
	}

	for (int i = 0; i < n; ++i)
		cin >> money[i];

	fill(ans, ans + n, INT_MIN);
	bool flag = false;
	bool update = true;
	int cnt = 0;
	ans[s] = money[s]; // 돈 벌고 시작

	// 벨만포드 ( 싸이클에 포함된 정점 체크)
	while (update && cnt != n) {
		update = false;
		for (int i = 0; i < n; i++)
			for (auto j : info[i]) {
				if (ans[i] != INT_MIN && ans[i] + money[j.first] - j.second > ans[j.first]) {
					ans[j.first] = ans[i] + money[j.first] - j.second;
					update = true;

					if (cnt == n - 1)
						gees[i] = true;
				}
			}
		cnt++;
	}

	// bfs
	queue<int> q;
	bool gee = false;
	for (int i = 0; i < n; ++i)
		if (gees[i])
			q.push(i);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (check[now])
			continue;

		check[now] = true;

		for (int i = 0; i < info[now].size(); ++i) {
			if (info[now][i].first == e) {
				gee = true;
				break;
			}
			if (!check[info[now][i].first])
				q.push(info[now][i].first);
		}

		if (gee)
			break;
	}


	if (ans[e] == INT_MIN)
		cout << "gg";
	else if (gee)
		cout << "Gee";
	else
		cout << ans[e];
	return 0;
}