#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int degree[32001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> info(n+1);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		info[a].push_back(b);
		++degree[b];
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i) {		// 차수가 0인 정점 push
		if (degree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int d = q.front();
		q.pop();
		cout << d << " ";
		for (auto a : info[d]) {
			--degree[a];
			if (degree[a] == 0)
				q.push(a);
		}
	}
	return 0;
}