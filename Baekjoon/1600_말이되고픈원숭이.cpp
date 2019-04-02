#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
const int hx[] = { 2,1,-1,-2,-2,-1,1,2 };
const int hy[] = { -1,-2,-2,-1,1,2,2,1 };

struct pos {
	int y;
	int x;
	int hc;
	int tc;
};

int bj_1600() {
	int ans = INT_MAX;
	int K;
	cin >> K;
	int N, M;
	cin >> M >> N;
	vector<vector<int>> map(N, vector<int>(M));
	vector<vector<vector<bool>>> check(N, vector<vector<bool>>(M,vector<bool>(K+1,false)));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> map[i][j];
	}

	queue<pos> q;
	q.push({0,0,0,0});
	check[0][0][0] = true;

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int hcount = q.front().hc;
		int tcount = q.front().tc;
		q.pop();

		if (y == N - 1 && x == M - 1) {			// 도착
			cout << tcount;
			return 0;
		}

		for (int k = 0; k < 4; ++k) {			// 인접한 1칸 움직일때
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M || check[ny][nx][hcount] || map[ny][nx] == 1)		// 맵 밖 or 갔던 곳 or 벽
				continue;

			q.push({ny,nx,hcount,tcount+1});
			check[ny][nx][hcount] = true;
		}

		if (hcount < K) {
			for (int k = 0; k < 8; ++k) {
				int ny = y + hy[k];
				int nx = x + hx[k];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M || check[ny][nx][hcount+1] || map[ny][nx] == 1)		// 맵 밖 or 갔던 곳 or 벽
					continue;
				q.push({ny,nx,hcount + 1,tcount + 1});
				check[ny][nx][hcount + 1] = true;
			}
		}
	}
	cout << -1;
	return 0;
}