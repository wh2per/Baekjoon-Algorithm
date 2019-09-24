#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 위상정렬

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n;
		cin >> n;

		vector<int> degree(n + 1, 0);
		vector<vector<bool>> info(n + 1,vector<bool>(n+1,false));

		for (int i = 0; i < n; ++i) {		// 차수 초기화0
			int num;
			cin >> num;
			degree[num] = i;
		}

		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (degree[i] < degree[j])
					info[i][j] = true;
				else
					info[j][i] = true;
			}
		}

		int m;
		cin >> m;
		
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;

			if (info[a][b]) {
				info[a][b] = false;
				info[b][a] = true;
				++degree[a];
				--degree[b];
			}
			else {
				info[a][b] = true;
				info[b][a] = false;
				--degree[a];
				++degree[b];
			}
		}
		
		queue<int> q;
		for (int i = 1; i <= n; ++i) {
			if (degree[i] == 0)
				q.push(i);
		}

		if (q.size() > 1)
			cout << "?\n";
		else {
			vector<int> ans;
			while (!q.empty()) {
				int d = q.front();
				q.pop();

				ans.push_back(d);
				for (int i = 1; i <= n; ++i) {
					if (info[d][i]) {
						--degree[i];
						if (degree[i] == 0)
							q.push(i);
					}
				}
			}

			if (ans.size() != n)
				cout << "IMPOSSIBLE\n";
			else {
				for (auto a : ans)
					cout << a << " ";
				cout << "\n";
			}
		}
	}
	return 0;
}