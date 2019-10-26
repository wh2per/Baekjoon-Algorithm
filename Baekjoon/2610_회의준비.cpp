#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

vector<vector<int>> info;
vector<bool> check;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int n,m;
	cin >> n >> m;

	info.assign(n + 1, vector<int>(n + 1, 0));
	check.assign(n + 1, false);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		info[a][b] = 1;
		info[b][a] = 1;
	}

	for (int i = 1; i <= n; ++i) {		// 경유
		for (int j = 1; j <= n; ++j) {	// 시작점
			if (info[j][i] == 0)		//  시작-경유 가는길이 없으면
				continue;
			for (int k = 1; k <= n; ++k) { 	// 도착점
				if (info[i][k] == 0 || j == k)			// 경유-도착 가는길이 없거나 시작=도착이면
					continue;
				if (info[j][k] == 0 || info[j][k] > info[j][i] + info[i][k])		// 시작-도착 길이 없거나 경유하는 것보다 클때
					info[j][k] = info[j][i] + info[i][k];
			}
		}
	}
	
	vector<int> ans;

	for (int k = 1; k <= n; ++k) {
		if (check[k])
			continue;
		int ans_num = k;
		int ans_max = INT_MAX;
		
		queue<int> q;
		q.push(k);
		while (!q.empty()) {
			int pos = q.front();
			q.pop();

			int pos_max = INT_MIN;
			for (int i = 1; i <= n; ++i) {
				int a = info[pos][i];
				if (a != 0) {
					if (pos_max < a) 
						pos_max = a;

					if (!check[i]) {
						check[i] = true;
						q.push(i);
					}
				}
			}
			
			if (pos_max < ans_max) {
				ans_num = pos;
				ans_max = pos_max;
			}
		}
		ans.push_back(ans_num);
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (auto a : ans)
		cout << a << "\n";

	return 0;
}