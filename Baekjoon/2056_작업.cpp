#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

vector<int> degree;
vector<int> time;
vector<vector<int>> info;
vector<int> dist;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int n;
	cin >> n;
	
	time.assign(n + 1, 0);
	degree.assign(n + 1, 0);
	info.assign(n + 1, vector<int>());
	dist.assign(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		cin >> time[i];
		dist[i] = time[i];
		
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; ++j) {
			int num;
			cin >> num;

			info[i].push_back(num);
			++degree[num];
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i) {		// 차수가 0인 정점 push
		if (degree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int d = q.front();
		q.pop();
		for (auto a : info[d]) {
			dist[a] = max(dist[a], time[a] + dist[d]);

			--degree[a];
			if (degree[a] == 0)
				q.push(a);
		}
	}

	cout << *max_element(dist.begin(), dist.end());

	return 0;
}