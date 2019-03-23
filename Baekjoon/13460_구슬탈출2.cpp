#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>	
using namespace std;

typedef struct info {
	int rx;
	int ry;
	int bx;
	int by;
	int count;
}INFO;

int bj_13460(){
	int ans = -1;
	INFO pos;
	int N, M;
	cin >> N >> M;
	vector<vector<char>> map(N, vector<char>(M));

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'R') {
				pos.rx = j;
				pos.ry = i;
			}
			else if(map[i][j] == 'B'){
				pos.bx = j;
				pos.by = i;
			}
		}
	}
	pos.count = 0;

	queue<INFO> q;
	bool visited[10][10][10][10] = {false,};
	int dy[] = { -1, 1, 0, 0 };
	int dx[] = { 0, 0, -1, 1 };
	
	q.push(pos);
	visited[pos.ry][pos.rx][pos.by][pos.bx] = true;

	while (!q.empty()) {
		INFO cur = q.front();
		q.pop();
		if (cur.count > 10)
			break;

		if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O') {
			ans = cur.count;
			break;
		}

		for (int dir = 0; dir < 4; ++dir) {			// 4가지 방향으로 모두 이동  -> 사실 이전에 갔던 방향이나, 이전에 갔던 방향의 반대 방향으로는 갈 필요 없음
			int next_ry = cur.ry;
			int next_rx = cur.rx;
			int next_by = cur.by;
			int next_bx = cur.bx;

			while (1) {			// 빨간공 이동
				if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O') {		// 벽도 아니고 구멍도 아닐때
					next_ry += dy[dir];
					next_rx += dx[dir];
				}
				else {
					if (map[next_ry][next_rx] == '#') {			// 현재 벽일 때 한칸 이전으로 이동
						next_ry -= dy[dir];
						next_rx -= dx[dir];
					}
					break;
				}
			}

			while (1) {		// 파란공 이동
				if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O') {		// 벽도 아니고 구멍도 아닐때
					next_by += dy[dir], next_bx += dx[dir];
				}
				else {
					if (map[next_by][next_bx] == '#') {			// 현재 벽일 때 한칸 이전으로 이동
						next_by -= dy[dir], next_bx -= dx[dir];
					}
					break;
				}
			}

			if (next_ry == next_by && next_rx == next_bx) {			// 빨간공과 파란공이 같은 위치에 있을 때
				if (map[next_ry][next_rx] != 'O') {					// 게임이 끝난게 아니라면
					int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);		// 빨간공 이동거리 측정
					int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);		// 파란공 이동거리 측정
					if (red_dist > blue_dist) {
						next_ry -= dy[dir], next_rx -= dx[dir];							// 더 많이 움직인 공이 한칸 뒤로
					}
					else {
						next_by -= dy[dir], next_bx -= dx[dir];
					}
				}
			}

			if (visited[next_ry][next_rx][next_by][next_bx] == false) {
				visited[next_ry][next_rx][next_by][next_bx] = true;
				INFO next;
				next.ry = next_ry;
				next.rx = next_rx;
				next.by = next_by;
				next.bx = next_bx;
				next.count = cur.count + 1;
				q.push(next);
			}
		}
	}

	cout << ans;

	return 0;
}