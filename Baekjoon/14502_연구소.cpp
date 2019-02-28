#include <iostream>
#include <queue>
using namespace std;
int n_14502, m_14502;
int a_14502[10][10];
int b_14502[10][10];
int dx_14502[] = { 0,0,1,-1 };
int dy_14502[] = { 1,-1,0,0 };
int bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < n_14502; i++) {
		for (int j = 0; j < m_14502; j++) {
			b_14502[i][j] = a_14502[i][j];
			if (b_14502[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx_14502[k];
			int ny = y + dy_14502[k];
			if (0 <= nx && nx < n_14502 && 0 <= ny && ny < m_14502) {
				if (b_14502[nx][ny] == 0) {
					b_14502[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n_14502; i++) {
		for (int j = 0; j < m_14502; j++) {
			if (b_14502[i][j] == 0) {
				cnt += 1;
			}
		}
	}
	return cnt;
}
int bj_14502() {
	cin >> n_14502 >> m_14502;
	for (int i = 0; i < n_14502; i++) {
		for (int j = 0; j < m_14502; j++) {
			cin >> a_14502[i][j];
		}
	}
	int ans = 0;
	for (int x1 = 0; x1 < n_14502; x1++) {
		for (int y1 = 0; y1 < m_14502; y1++) {
			if (a_14502[x1][y1] != 0) continue;
			for (int x2 = 0; x2 < n_14502; x2++) {
				for (int y2 = 0; y2 < m_14502; y2++) {
					if (a_14502[x2][y2] != 0) continue;
					for (int x3 = 0; x3 < n_14502; x3++) {
						for (int y3 = 0; y3 < m_14502; y3++) {
							if (a_14502[x3][y3] != 0) continue;
							if (x1 == x2 && y1 == y2) continue;
							if (x1 == x3 && y1 == y3) continue;
							if (x2 == x3 && y2 == y3) continue;
							a_14502[x1][y1] = 1;
							a_14502[x2][y2] = 1;
							a_14502[x3][y3] = 1;
							int cur = bfs();
							if (ans < cur) ans = cur;
							a_14502[x1][y1] = 0;
							a_14502[x2][y2] = 0;
							a_14502[x3][y3] = 0;
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}