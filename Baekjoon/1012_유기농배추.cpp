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

	//freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	while (T--) {
		int m, n,k;
		cin >> m >> n>>k;

		vector<vector<int>> v(n, vector<int>(m, 0));
		while (k--) {
			int x, y;
			cin >> x >> y;

			v[y][x] = 1;
		}

		int cnt = 0;
		queue<pair<int, int>> q;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (v[i][j] == 0 || v[i][j]==2)
					continue;

				q.push({ i,j });
				++cnt;
				while (!q.empty()) {
					int cy = q.front().first;
					int cx = q.front().second;
					v[cy][cx] = 2;
					q.pop();

					for (int d = 0; d < 4; ++d) {
						int ny = cy + dy[d];
						int nx = cx + dx[d];

						if (nx < 0 || nx >= m || ny < 0 || ny >= n || v[ny][nx] == 0 || v[ny][nx] == 2)
							continue;
						q.push({ny,nx});
						v[ny][nx] = 2;
					}
				}
			}
		}
		cout << cnt << '\n';
	}


	return 0;
}