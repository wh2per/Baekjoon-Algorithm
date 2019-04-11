#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int bj_5427() {
	int t;
	cin >> t;

	for (int w = 0; w < t; ++w) {
		int n, m;
		int ans = 0;
		pair<int, int> start;					// 시작위치
		vector<pair<int, int>> fire;			// 불 위치
		cin >> m >> n;
		vector<vector<char>> map(n, vector<char>(m));
		vector<vector<bool>> check(n, vector<bool>(m, false));
		for (int i = 0; i < n; ++i) {			// map 입력
			for (int j = 0; j < m; ++j) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					start.first = i;
					start.second = j;
					map[i][j] = '.';
				}
				else if (map[i][j] == '*') {
					fire.push_back({i,j});
				}
			}
		}

		queue<pair<int, int>> q;
		q.push(start);
		check[start.first][start.second] = true;
		bool flag = false;
		while (!q.empty()) {
			int size = q.size();
			for (int g = 0; g < size; ++g) {
				int y = q.front().first;
				int x = q.front().second;
				q.pop();

				if (map[y][x] == '*')
					continue;

				if (y == n - 1 || x == m - 1 || y==0 || x==0) {			// 탈출 조건
					++ans;
					flag = true;
					break;
				}

				// 상근이 이동
				for (int k = 0; k < 4; ++k) {
					int ny = y + dy[k];
					int nx = x + dx[k];

					if (ny < 0 || ny >= n || nx < 0 || nx >= m)		// 맵범위 밖
						continue;
					if (check[ny][nx] || map[ny][nx] == '#' || map[ny][nx] == '*')		// 갔던길, 벽, 불인 경우 스킵
						continue;

					q.push({ ny,nx });
					check[ny][nx] = true;
				}
			}

			if (flag)
				break;

			// 불부터 번지기
			int fsize = fire.size();
			vector<pair<int, int>> temp;
			for (int f = 0; f < fsize; ++f) {
				int fy = fire[f].first;
				int fx = fire[f].second;

				for (int k = 0; k < 4; ++k) {
					int fny = fy + dy[k];
					int fnx = fx + dx[k];

					if (fny < 0 || fny >= n || fnx < 0 || fnx >= m)		// 맵범위 밖
						continue;
					if (map[fny][fnx] == '#' || map[fny][fnx] == '*')		// 벽이거나 불인 경우 스킵
						continue;

					map[fny][fnx] = '*';
					temp.push_back({fny,fnx});
				}
			}
			fire = temp;
			
			++ans;
		}
		if (flag)
			cout << ans << '\n';
		else
			cout << "IMPOSSIBLE" << '\n';
	}
	return 0;
}