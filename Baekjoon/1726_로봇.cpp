#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { 1,0,-1,0 };		// 동 남 서 북   실제로는 동 서 남 북
const int dy[] = { 0,1,0,-1 };

struct info_robot {
	int y;
	int x;
	int dir;
	int count;
};

int bj_1726(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = 0;
	int n, m;
	cin >> n >> m;

	vector<vector<int>> map(n, vector<int>(m));
	vector<vector<vector<bool>>> check(n, vector<vector<bool>>(m, vector<bool>(4, false)));
	for (int i = 0; i < n; ++i) {		// 맵 입력
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];
	}

	pair<int, int> start;
	pair<int, int> end;
	int sdir, edir;
	cin >> start.first >> start.second >> sdir;
	cin >> end.first >> end.second >> edir;
	--start.first;
	--start.second;
	--end.first;
	--end.second;
	if (sdir == 1 || sdir == 4)
		--sdir;
	else {
		if (sdir == 3)
			sdir = 1;
	}

	if (edir == 1 || edir == 4)
		--edir;
	else {
		if (edir == 3)
			edir = 1;
	}

	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { start.first, start.second }, { sdir, 0 } });
	check[start.first][start.second][sdir] = true;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int dir = q.front().second.first;
		int count = q.front().second.second;
		q.pop();

		if (y == end.first && x == end.second && dir == edir) {		// 도착
			cout << count;
			return 0;
		}

		for (int u = 1; u < 4; ++u) {		// 전진 칸 
			int uy = y + (u*dy[dir]);
			int ux = x + (u*dx[dir]);

			if (uy < 0 || uy >= n || ux < 0 || ux >= m)		// 범위 밖 스킵
				break;
			if (map[uy][ux] == 1)		// 벽
				break;
			if (check[uy][ux][dir])
				continue;
			q.push({ { uy,ux},{dir,count + 1 } });
			check[uy][ux][dir] = true;
		}


		for (int k = 0; k < 4; ++k) {			// 방향 전환
			int ndir = (dir + k) % 4;
			if ((ndir + 6) % 4 == dir || ndir==dir)			// 왔던길로는 돌아가지 않음
				continue;

			int nc = count +1;
			
			if (!check[y][x][ndir]) {
				check[y][x][ndir] = true;
				q.push({ { y,x }, {ndir, nc} });
			}
		}
	}

	return 0;
}