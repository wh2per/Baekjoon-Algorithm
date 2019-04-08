#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>
using namespace std;

const int dx[] = { 1,0,-1,0 };		// 오른쪽, 아래, 왼쪽, 위
const int dy[] = { 0,1,0,-1 };

vector<vector<int>> prison_bfs(vector<vector<char>>& map, int y, int x, int n, int m) {
	vector<vector<int>> prison(n + 2, vector<int>(m + 2, 0));				// 각 위치마다 사용한 키의 갯수를 저장
	vector<vector<bool>> check(n + 2, vector<bool>(m + 2, false));

	deque<pair<int, int>> q;
	q.push_front({y,x});
	check[y][x] = true;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop_front();

		for (int k = 0; k < 4; ++k) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || ny >= n + 2 || nx < 0 || nx >= m+2 || check[ny][nx] || map[ny][nx]=='*')
				continue;

			if (map[ny][nx] == '#') {		// 벽인 경우는 뒤로 추가
				check[ny][nx] = true;
				prison[ny][nx] = prison[y][x] + 1;
				q.push_back({ ny,nx });
			}
			else {				// 빈공간인 경우는 앞으로 추가
				check[ny][nx] = true;
				prison[ny][nx] = prison[y][x];
				q.push_front({ ny,nx });
			}
		}
	}
	return prison;
}

int bj_9367() {
	int t;
	cin >> t;
	for (int q = 0; q < t; ++q) {
		vector<pair<int, int>> ppos;
		int ans = INT_MAX;
		int n, m;
		cin >> n >> m;
		ppos.push_back({0,0});			// 외부조력자 추가
		vector<vector<char>> map(n+2, vector<char>(m+2,'.'));
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> map[i][j];
				if (map[i][j] == '$') {			// 죄수위치 기억
					ppos.push_back({ i,j });
					map[i][j] = '.';
				}
			}
		}

		vector<vector<vector<int>>> prisoner(3, vector<vector<int>>());		// 외부조력자, 죄수1, 죄수2
		for (int i = 0; i < 3; ++i) 
			prisoner[i] = prison_bfs(map, ppos[i].first, ppos[i].second, n, m);

		for (int i = 0; i < n + 2; ++i) {
			for (int j = 0; j < m + 2; ++j) {
				if (map[i][j] == '*')
					continue;

				int temp = 0;
				for (int k = 0; k < 3; ++k)
					temp += prisoner[k][i][j];

				if (map[i][j] == '#')
					temp -= 2;

				if (ans > temp)
					ans = temp;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}