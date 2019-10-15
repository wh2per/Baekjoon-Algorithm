#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

struct pos {
	int r;
	int y;
	int x;
	int time;
};

vector<vector<vector<char>>> arr;
vector<vector<vector<bool>>> visited;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r",stdin);

	while (1) {
		int l, r, c;
		cin >> l >> r >> c;

		if (l == 0 && r == 0 && c == 0)
			break;

		arr.assign(l, vector<vector<char>>(r, vector<char>(c, 0)));
		visited.assign(l, vector<vector<bool>>(r, vector<bool>(c, false)));

		int startr, starty, startx, endr, endy, endx;
		char temp;
		for (int i = 0; i < l; ++i) {
			for (int j = 0; j < r; ++j) {
				for (int k = 0; k < c; ++k) {
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S') {		// 시작점
						startr = i;
						starty = j;
						startx = k;
					}
					else if (arr[i][j][k] == 'E') {		// 도착점
						endr = i;
						endy = j;
						endx = k;
					}
				}
			}
		}

		int ans = INT_MAX;
		queue<pos> q;
		visited[startr][starty][startx] = true;
		q.push({startr, starty, startx, 0});
		while (!q.empty()) {
			int cr = q.front().r;
			int cy = q.front().y;
			int cx = q.front().x;
			int time = q.front().time;
			q.pop();

			if (cr == endr && cy == endy && cx == endx) {
				ans = time;
				break;
			}

			// 위층 가능한지 검사
			if (cr - 1 >= 0) {
				int nr = cr - 1;
				if (!visited[nr][cy][cx] && arr[nr][cy][cx] != '#') {
					visited[nr][cy][cx] = true;
					q.push({ nr,cy,cx,time + 1 });
				}
			}
			// 아래층 가능한지 검사
			if (cr + 1 < l) {
				int nr = cr + 1;

				if (!visited[nr][cy][cx] && arr[nr][cy][cx] != '#') {
					visited[nr][cy][cx] = true;
					q.push({ nr,cy,cx,time + 1 });
				}
			}
			// 4방향 가능한지 검사
			for (int k = 0; k < 4; ++k) {
				int ny = cy + dy[k];
				int nx = cx + dx[k];

				if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited[cr][ny][nx] || arr[cr][ny][nx] == '#')
					continue;
				visited[cr][ny][nx] = true;
				q.push({cr,ny,nx,time+1});
			}
		}

		if (ans == INT_MAX)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << ans << " minute(s).\n";
	}

	return 0;
}