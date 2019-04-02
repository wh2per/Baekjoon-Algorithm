#include <iostream>
#include <queue>
#include <climits>
using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int bj_1938() {
	int ans = INT_MAX;
	int N;
	cin >> N;

	vector<pair<int, int>> start;
	vector<pair<int, int>> end;
	vector<vector<char>> map(N,vector<char>(N));
	for (int i = 0; i < N; ++i) {			// 맵 입력
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'B')
				start.push_back({ i,j });
			else if (map[i][j] == 'E')
				end.push_back({i,j});
		}
	}

	bool bdir = true;			// 기본 세로로 초기화
	if (start[0].first == start[1].first)			// 가로 : false, 세로 : true
		bdir = false;
	bool edir = true;
	if (end[0].first == end[1].first)
		edir = false;

	queue<pair<pair<int, int>, pair<bool,int>>> q;		// <y, x> <dir,count>
	vector<vector<vector<bool>>> check(N, vector<vector<bool>>(N, vector<bool>(2,false)));
	q.push({ start[1],{bdir,0} });
	check[start[1].first][start[1].second][bdir] = true;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		bool dir = q.front().second.first;
		int count = q.front().second.second;
		q.pop();

		if (y == end[1].first && x == end[1].second && dir == edir) {		// 도착!
			if (ans > count)
				ans = count;
			continue;
		}

		for (int k = 0; k < 4; ++k) {			// 4방향 검사
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N || check[ny][nx][dir] || map[ny][nx]=='1')
				continue;
			if (dir) {		// 세로
				if (ny - 1 < 0 || ny + 1 >= N || map[ny - 1][nx] == '1' || map[ny + 1][nx] == '1')
					continue;
				q.push({ { ny,nx }, {dir,count + 1} });
				check[ny][nx][dir] = true;
			}
			else {			// 가로
				if (nx - 1 < 0 || nx + 1 >= N || map[ny][nx - 1] == '1' || map[ny][nx + 1] == '1')
					continue;
				q.push({ {ny,nx},{dir,count + 1} });
				check[ny][nx][dir] = true;
			}
		}

		if (dir) {			// 방향 전환 검사		세로->가로
			if (!check[y][x][!dir]) {
				int k;
				for (k = 0; k < 3; ++k) {
					if (x - 1 < 0 || x + 1 >= N || y - 1 < 0 || y + 1 >= N)
						break;
					if (map[y -1 + k][x + 1] == '1' || map[y - 1 + k][x - 1] == '1')
						break;
				}
				if (k == 3) {
					q.push({ {y,x},{!dir,count + 1} });
					check[y][x][!dir] = true;
				}
			}
		}
		else {		// 가로->세로
			if (!check[y][x][!dir]) {
				int k;
				for (k = 0; k < 3; ++k) {
					if (x - 1 < 0 || x + 1 >= N || y - 1 < 0 || y + 1 >= N)
						break;
					if (map[y - 1][x - 1 + k] == '1' || map[y + 1][x - 1 + k] == '1')
						break;
				}
				if (k == 3) {
					q.push({ {y,x},{!dir,count + 1} });
					check[y][x][!dir] = true;
				}
			}
		}
	}
	if (ans == INT_MAX)
		ans = 0;
	cout << ans;

	return 0;
}