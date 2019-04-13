#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

const int dx[] = { 1,0,-1,0 };			// 오른, 아래, 왼쪽, 위
const int dy[] = { 0,1,0,-1 };
const char dir[] = { '|','-','+','1','2','3','4' };
map<char, set<int>> gas_pipe = { {'|',{1,3}},{'-',{0,2}},{'+',{0,1,2,3}},{'1',{0,1}},{'2',{0,3}},{'3',{2,3}},{'4',{1,2}} };

struct info_gas {
	int y;
	int x;
	int dir;
};

int bj_2931() {
	int r, c;
	cin >> r >> c;
	vector<vector<char>> map(r, vector<char>(c));
	pair<int, int> start;
	pair<int, int> end;

	// 맵 입력
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'M')
				start = { i,j };
			else if (map[i][j] == 'Z')
				end = {i,j};
		}
	}

	int sdir = -1;
	for (int k = 0; k < 4; ++k) {
		int ky = start.first + dy[k];
		int kx = start.second + dx[k];

		if (ky < 0 || ky >= r || kx < 0 || kx >= c) 
			continue;
		if (map[ky][kx] != '.' && gas_pipe[map[ky][kx]].count((k+6)%4)>0) {
			sdir = k;
			break;
		}
	}

	queue<info_gas> q;
	q.push({start.first,start.second,sdir});
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		q.pop();

		if (map[y][x] == '.') {
			set<int> needs;
			for (int k = 0; k < 4; ++k) {
				int ky = y + dy[k];
				int kx = x + dx[k];

				if (ky < 0 || ky >= r || kx < 0 || kx >= c)
					continue;
				if (gas_pipe[map[ky][kx]].count((k+6)%4)>0)
					needs.insert(k);
			}

			char ans= '=';
			for (auto a : gas_pipe) {
				if (a.second == needs) {
					ans = a.first;
					break;
				}
			}

			cout << y+1 << " " << x+1 << " " << ans;
			break;
		}

		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (map[ny][nx] == '|' || map[ny][nx] == '-' || map[ny][nx] == '+') {			// 현재 방향 채택
			q.push({ny,nx,dir});
		}
		else {			// 현재 방향의 반대를 제외한 방향 채택
			int ndir = -1;
			for (int a : gas_pipe[map[ny][nx]]) {
				if (a != (dir+6)%4) {
					ndir = a;
					break;
				}
			}
			q.push({ny,nx,ndir});
		}
	}
	
	return 0;
}