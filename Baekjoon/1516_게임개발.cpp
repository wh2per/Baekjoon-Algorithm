#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> build(n+1);
	vector<int> time(n + 1);
	vector<int> cost(n + 1);
	vector<int> degree(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> time[i];
		while (1) {
			int num;
			cin >> num;
			if (num == -1)
				break;
			build[num].push_back(i);
			++degree[i];
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i) {		// degree가 0인 정점만 push
		if (degree[i] == 0) {
			q.push(i);
			cost[i] = time[i];
		}
	}
	while (!q.empty()) {
		int d = q.front();
		q.pop();
		for (auto a : build[d]) {
			--degree[a];
			cost[a] = max(cost[a], cost[d] + time[a]);
			if (degree[a] == 0)
				q.push(a);
		}
	}

	for (int i=1; i<=n; ++i)
		cout << cost[i]<< "\n";
	return 0;
}