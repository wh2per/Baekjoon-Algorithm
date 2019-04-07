#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = {1,0,-1,0};		// 오른쪽, 아래, 왼쪽, 위
const int dy[] = {0,1,0,-1};

vector<vector<int>> panda_map;
vector<vector<int>> panda_live;
int panda_n;

int panda_dfs(int y, int x) {
	if (panda_live[y][x] > 0)
		return panda_live[y][x];

	int temp = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= panda_n || nx < 0 || nx >= panda_n || panda_map[y][x] >= panda_map[ny][nx])
			continue;

		temp = max(temp, panda_dfs(ny, nx)+1);
	}
	panda_live[y][x] = temp;
	return temp;
}
int bj_1937() {
	int ans = 1;
	cin >> panda_n;

	panda_map.assign(panda_n, vector<int>(panda_n));
	panda_live.assign(panda_n, vector<int>(panda_n, 0));

	for(int i=0; i<panda_n; ++i){
		for (int j = 0; j < panda_n; ++j) {
			cin >> panda_map[i][j];
		}
	}

	for (int i = 0; i < panda_n; ++i) {				// 판다 시작 지점 모두 검사
		for (int j = 0; j < panda_n; ++j){ 
			ans = max(ans, panda_dfs(i, j));
		}
	}

	cout << ans;
	return 0;
}