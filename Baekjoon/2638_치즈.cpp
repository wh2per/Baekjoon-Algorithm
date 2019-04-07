#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { 1,0,-1,0 };		// 오른쪽, 아래, 왼쪽, 위
const int dy[] = { 0,1,0,-1 };

int bj_2638() {
	int ans = 0;
	int n, m;
	cin >> n >> m;

	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;

	vector<vector<int>> map(n, vector<int>(m));
	vector<vector<bool>> check(n, vector<bool>(m,false));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1)				// 치즈 위치 저장
				q1.push({ i,j });
		}
	}

	q2.push({0,0});
	check[0][0] = true;
	while (!q1.empty()) {
		// 바깥 위치 표시
		while (!q2.empty()) {
			int y = q2.front().first;
			int x = q2.front().second;
			map[y][x] = 0;
			check[y][x] = true;
			q2.pop();

			for (int k = 0; k < 4; ++k) {
				int ny = y + dy[k];
				int nx = x + dx[k];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m || check[ny][nx] || map[ny][nx]==1)
					continue;
				check[ny][nx] = true;
				q2.push({ny,nx});
			}
		}

		int size = q1.size();
		for (int i = 0; i < size; ++i) {				// 치즈들 한바퀴 검사
			int y = q1.front().first;
			int x = q1.front().second;
			q1.pop();

			int count = 0;
			for (int k = 0; k < 4; ++k) {
				int ny = y + dy[k];
				int nx = x + dx[k];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m || !check[ny][nx])
					continue;
				++count;
			}

			if (count > 1) {
				q2.push({y,x});
				map[y][x] = 0;
			}else
				q1.push({ y,x });

		}
		++ans;
	}

	cout << ans;
	return 0;
}