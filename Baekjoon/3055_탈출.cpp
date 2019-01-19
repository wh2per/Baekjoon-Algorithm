#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <tuple>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int bj_3055() {
	int water[50][50];
	int d[50][50];
	int dx[] = { 1,-1,0,0, };		//오른쪽 왼쪽 위 아래
	int dy[] = { 0,0,-1,1 };
	int r, c;
	cin >> r >> c;
	vector<string> a(r);
	queue<pair<int, int>> q;
	for (int i = 0; i < r; i++) {
		cin >> a[i];
	}
	memset(water, -1, sizeof(water));
	int sx, sy, ex, ey;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] == '*') {
				q.push(make_pair(i, j));
				water[i][j] = 0;
			}
			else if (a[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (a[i][j] == 'D') {
				ex = i;
				ey = j;
			}
		}
	}

	while (!q.empty()) {		//물을 시간별로 세팅
		int wx = q.front().first;
		int wy = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = wx + dx[k];
			int ny = wy + dy[k];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (water[nx][ny] != -1)
				continue;
			if (a[nx][ny] == 'X')
				continue;
			if (a[nx][ny] == 'D')
				continue;

			water[nx][ny] = water[wx][wy] + 1;
			q.push(make_pair(nx, ny));
		}
	}

	memset(d, -1, sizeof(d));
	q.push(make_pair(sx, sy));
	d[sx][sy] = 0;		// 시작지점

	while (!q.empty()) {		//이동해 봅시다
		int mx = q.front().first;
		int my = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = mx + dx[k];
			int ny = my + dy[k];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (d[nx][ny] != -1)
				continue;
			if (a[nx][ny] == 'X')
				continue;
			if (water[nx][ny] != -1 && d[mx][my] + 1 >= water[nx][ny])
				continue;
			d[nx][ny] = d[mx][my] + 1;
			q.push(make_pair(nx, ny));
		}
	}

	if (d[ex][ey] == -1) {
		cout << "KAKTUS\n";
	}
	else {
		cout << d[ex][ey] << '\n';
	}

	return 0;
}