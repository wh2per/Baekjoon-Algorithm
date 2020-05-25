#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

char arr[101][101];
bool check[101][101];
queue<pair<pair<int, int>, int>> q;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n, m;
int ans;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ans = INT_MAX;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];
	}

	q.push({ {0,0},1 });
	check[0][0] = true;
	while (!q.empty()) {
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (cy == n - 1 && cx == m - 1) {
			if (ans > cnt)
				ans = cnt;
			continue;
		}

		for (int k = 0; k < 4; ++k) {
			int ny = cy + dy[k];
			int nx = cx + dx[k];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || check[ny][nx] || arr[ny][nx] == '0')
				continue;

			check[ny][nx] = true;
			q.push({ {ny,nx},cnt + 1 });
		}
	}

	cout << ans;

	return 0;
}

