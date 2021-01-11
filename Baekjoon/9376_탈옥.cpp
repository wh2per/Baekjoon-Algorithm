#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <string.h>
using namespace std;

const int dx[] = { 1,0,-1,0 };		// 오른쪽, 아래, 왼쪽, 위
const int dy[] = { 0,1,0,-1 };

vector<pair<int, int>> ppos;
char map[103][103];
int n, m;

int prisoner[3][103][103];		// 각 위치마다 사용한 키의 갯수를 저장
bool check[103][103];

void prison_bfs(int idx,int y, int x) {
	for (int i = 0; i < n + 2; ++i) {		
		for (int j = 0; j < m + 2; ++j) 				
			prisoner[idx][i][j] = INT_MAX;
	}
	memset(check, false, sizeof(check));

	deque<pair<int, int>> q;
	q.push_front({y,x});
	check[y][x] = true;
	prisoner[idx][y][x] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop_front();

		for (int k = 0; k < 4; ++k) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || ny >= n + 2 || nx < 0 || nx >= m+2 || check[ny][nx] || map[ny][nx]=='*')
				continue;

			if (map[ny][nx] == '#') {		// 문인 경우는 뒤로 추가
				check[ny][nx] = true;
				prisoner[idx][ny][nx] = prisoner[idx][y][x] + 1;
				q.push_back({ ny,nx });
			}
			else {				// 빈공간인 경우는 앞으로 추가
				check[ny][nx] = true;
				prisoner[idx][ny][nx] = prisoner[idx][y][x];
				q.push_front({ ny,nx });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int t;
	cin >> t;
	for (int q = 0; q < t; ++q) {
		cin >> n >> m;

		ppos.clear();
		ppos.push_back({0,0});			// 외부조력자 추가

		memset(map,'.',sizeof(map));
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> map[i][j];
				if (map[i][j] == '$') {			// 죄수위치 기억
					ppos.push_back({ i,j });
					map[i][j] = '.';
				}
			}
		}

		for (int i = 0; i < 3; ++i) 
			prison_bfs(i,ppos[i].first, ppos[i].second);

		int ans = INT_MAX;
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