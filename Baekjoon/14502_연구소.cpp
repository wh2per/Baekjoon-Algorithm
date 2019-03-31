#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

int bj_14502() {
	int ans = -1;
	int N, M;
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M));
	vector<pair<int, int>> vq;			// 바이러스 위치 저장
	vector<pair<int, int>> pos;
	int whole = N * M;
	int wall=0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				++wall;
			else if (map[i][j] == 2) 		// 바이러스 위치 저장
				vq.push_back({i,j});
			else 
				pos.push_back({ i,j });			// 빈칸 위치 저장
		}
	}

	vector<int> select(pos.size(), 1);
	select[0] = 0; select[1] = 0; select[2] = 0;
	do {
		vector<vector<int>> temp(map.begin(), map.end());
		vector<vector<bool>> check(N, vector<bool>(M, false));

		for (int i = 0; i < select.size(); ++i) {			// 벽 세팅
			if (select[i] == 0) {			// 선택된 위치
				temp[pos[i].first][pos[i].second] = 1;
			}
		}

		queue<pair<int, int>> q;
		for (int i = 0; i < vq.size(); ++i) 
			q.push(vq[i]);

		int tvirus = vq.size();
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int k = 0; k < 4; ++k) {
				int ny = y + dy[k];
				int nx = x + dx[k];

				if (ny<0 || ny>=N || nx < 0 || nx >= M)		// 맵 범위 벗어날 경우 
					continue;

				if (check[ny][nx] || temp[ny][nx] == 2 || temp[ny][nx]==1)		// 갔던 곳이나 이미 바이러스, 벽일 경우
					continue;

				temp[ny][nx] = 2;
				q.push({ ny,nx });
				++tvirus;
			}
		}
		if (whole - tvirus - wall - 3 > ans)
			ans = whole - tvirus - wall - 3;

	} while (next_permutation(select.begin(), select.end()));

	cout << ans;
	return 0;
}