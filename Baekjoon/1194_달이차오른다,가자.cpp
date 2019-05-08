#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int dy[] = {0,1,0,-1};
const int dx[] = {1,0,-1,0};

struct info_moon {
	int dy;
	int dx;
	int count;
	int key;
};

int bj_1194() {
	int answer = -1;
	info_moon start;
	int n, m;
	cin >> n >> m;

	vector<vector<char>> map(n, vector<char>(m));
	vector<vector<vector<bool>>> check(64,vector<vector<bool>>(n, vector<bool>(m,false)));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				start.dy = i;
				start.dx = j;
			}
		}
	}

	queue<info_moon> q;
	check[0][start.dy][start.dx] = true;
	start.key = 0;
	start.count = 0;
	q.push(start);

	while (!q.empty()) {
		info_moon curr = q.front();
		q.pop();

		if (map[curr.dy][curr.dx] == '1') {			// 도착
			answer = curr.count;
			break;
		}

		for (int k = 0; k < 4; ++k) {
			int ny = curr.dy + dy[k];
			int nx = curr.dx + dx[k];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || check[curr.key][ny][nx] || map[ny][nx]=='#')		// 범위 밖, 갔던 길, 벽
				continue;

			if (map[ny][nx] >= 'a') {		// 열쇠
				int newKey = curr.key | (1 << (int(map[ny][nx]) - 'a'));
				if (!check[newKey][ny][nx]) {
					info_moon next = curr;
					check[curr.key][ny][nx] = true;
					check[newKey][ny][nx] = true;
					next.count++;
					next.dy = ny;
					next.dx = nx;
					next.key = newKey;
					q.push(next);
				}
			}
			else if (map[ny][nx] >= 'A' && map[ny][nx] <= 'F') {		// 벽
				if (curr.key & 1 << (int(map[ny][nx]) - 'A')) {			// 가방에 열쇠가 있다면
					info_moon next = curr;
					check[curr.key][ny][nx] = true;
					next.count++;
					next.dy = ny;
					next.dx = nx;
					q.push(next);
				}
				else
					continue;
			}
			else {	// 빈공간
				info_moon next = curr;
				check[curr.key][ny][nx] = true;
				next.count++;
				next.dy = ny;
				next.dx = nx;
				q.push(next);
			}
		}
	}

	cout << answer;

	return 0;
}