#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = -1;
	int n, m;
	cin >> m >> n;
	vector<vector<int>> v(n, vector<int>(m, 0));
	queue<pair<int, int>> q;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];

			if (v[i][j] == 1)	// 익은 토마토
				q.push({ i,j });
		}
	}

	while (!q.empty()) {
		int size = q.size();

		for (int s = 0; s < size; ++s) {			// 현재 들어있는 갯수만큼 
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			for (int d = 0; d < 4; ++d) {
				int ny = cy + dy[d];
				int nx = cx + dx[d];

				if (nx < 0 || nx >= m || ny < 0 || ny >= n || v[ny][nx] == 1 || v[ny][nx] == -1)
					continue;
				q.push({ ny,nx });
				v[ny][nx] = 1;
			}
		}
		++ans;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}
