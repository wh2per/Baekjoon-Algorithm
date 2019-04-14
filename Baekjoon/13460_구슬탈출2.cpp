#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int dy[] = { 0,1,0,-1 };		// 오른쪽 아래 왼쪽 위
const int dx[] = { 1,0,-1,0 };

vector<vector<char>> map_ball;
int n_ball;
int m_ball;
int ans_ball;

void dfs_ball(int ry, int rx, int by, int bx, int count, int dir) {
	if (count >= 10)
		return;

	bool rflag = false;
	bool bflag = false;

	// 먼저 이동
	if ((dir == 0 && ry == by && rx < bx) || (dir == 2 && ry == by && rx > bx) || (dir == 1 && rx == bx && ry < by) || (dir == 3 && rx == bx && ry > by)) {		// b를 먼저 움직일 조건
		while (1) {
			int ny = by + dy[dir];
			int nx = bx + dx[dir];

			if (ny < 0 || ny >= n_ball || nx < 0 || nx >= m_ball || map_ball[ny][nx] == '#')
				break;

			if (map_ball[ny][nx] == 'O') {
				bflag = true;
				by = ny;
				bx = nx;
				break;
			}

			if (ny == ry && nx == rx)		// R을 만나면 정지
				break;

			by = ny;
			bx = nx;
		}

		while (1) {
			int ny = ry + dy[dir];
			int nx = rx + dx[dir];

			if (ny < 0 || ny >= n_ball || nx < 0 || nx >= m_ball || map_ball[ny][nx] == '#')
				break;

			if (map_ball[ny][nx] == 'O') {
				ry = ny;
				rx = nx;
				rflag = true;
				break;
			}

			if (ny == by && nx == bx)		// B을 만나면 정지
				break;

			ry = ny;
			rx = nx;
		}
	}
	else {			// r을 먼저 움직일 조건
		while (1) {
			int ny = ry + dy[dir];
			int nx = rx + dx[dir];

			if (ny < 0 || ny >= n_ball || nx < 0 || nx >= m_ball || map_ball[ny][nx] == '#')
				break;

			if (map_ball[ny][nx] == 'O') {
				ry = ny;
				rx = nx;
				rflag = true;
				break;
			}

			if (ny == by && nx == bx)		// B을 만나면 정지
				break;

			ry = ny;
			rx = nx;
		}

		while (1) {
			int ny = by + dy[dir];
			int nx = bx + dx[dir];

			if (ny < 0 || ny >= n_ball || nx < 0 || nx >= m_ball || map_ball[ny][nx] == '#')
				break;

			if (map_ball[ny][nx] == 'O') {
				bflag = true;
				by = ny;
				bx = nx;
				break;
			}

			if (ny == ry && nx == rx)		// R을 만나면 정지
				break;

			by = ny;
			bx = nx;
		}
	}

	if (rflag && !bflag) {			// 성공!
		if (ans_ball > count + 1)
			ans_ball = count + 1;
		return;
	}

	if (!rflag && !bflag) {			// 구슬이 둘 다 안빠졌을 때만 다음으로 진행
		// 다음 이동 방향을 정함
		for (int k = 0; k < 4; ++k) {
			if (k != dir && k != (dir + 6) % 4)			// 현재 방향과 반대방향은 제외
				dfs_ball(ry, rx, by, bx, count + 1, k);
		}
	}
}

int bj_13460() {
	ans_ball = INT_MAX;
	int ry, rx, by, bx;
	cin >> n_ball >> m_ball;
	map_ball.assign(n_ball, vector<char>(m_ball));

	for (int i = 0; i < n_ball; ++i) {
		for (int j = 0; j < m_ball; ++j) {
			cin >> map_ball[i][j];
			if (map_ball[i][j] == 'R') {
				ry = i;
				rx = j;
				map_ball[i][j] = '.';
			}
			else if (map_ball[i][j] == 'B') {
				by = i;
				bx = j;
				map_ball[i][j] = '.';
			}
		}
	}

	for (int k = 0; k < 4; ++k)
		dfs_ball(ry, rx, by, bx, 0, k);

	if (ans_ball == INT_MAX)
		cout << -1;
	else
		cout << ans_ball;

	return 0;
}