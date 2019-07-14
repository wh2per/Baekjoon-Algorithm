#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
int n_low;
int m_low;
vector<vector<int>> low_map;
vector<vector<int>> low_d;

int dfs_low(int y, int x) {
	if (y == n_low - 1 && x == m_low - 1) 
		return 1;

	if (low_d[y][x] == -1) {
		low_d[y][x] = 0;
		for (int k = 0; k < 4; ++k) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || nx < 0 || ny >= n_low || nx >= m_low)
				continue;
			if (low_map[y][x] > low_map[ny][nx])
				low_d[y][x] += dfs_low(ny, nx);
		}
	}
	
	return low_d[y][x];
}

int bj_1520() {
	cin >> n_low >> m_low;

	low_map.assign(n_low, vector<int>(m_low));
	low_d.assign(n_low, vector<int>(m_low,-1));

	for (int i = 0; i < n_low; ++i) {
		for (int j = 0; j < m_low; ++j)
			cin >> low_map[i][j];
	}

	cout << dfs_low(0, 0);
	return 0;
}