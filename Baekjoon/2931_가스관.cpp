#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

const int dx[] = { 1,0,-1,0 };			// 오른, 아래, 왼쪽, 위
const int dy[] = { 0,1,0,-1 };
const char dir[] = { '|','-','+','1','2','3','4' };
const map<char, set<int>> m = { {'|',{1,3}},{'-',{0,2}},{'+',{0,1,2,3}},{'1',{0,1}},{'2',{0,3}},{'3',{2,3}},{'4',{1,2}} };

struct info {
	int y;
	int x;
	int dir;
};

int bj_2931() {
	int ans = 0;
	pair<int, int> start;
	pair<int, int> end;
	int R, C;
	cin >> R >> C;
	vector<vector<char>> map(R, vector<char>(C));
	vector<vector<bool>> check(R, vector<bool>(C,false));

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			char c;
			cin >> c;
			map[i][j] = c;
			if (c == 'M') {
				start.first = i;
				start.second = j;
				check[i][j] = true;
			}
			else if (c == 'Z') {
				end.first = i;
				end.second = j;
				check[i][j] = true;
			}
			else if (c != '.') {		// 파이프라면
				set<int> s = m.at(c);
				for (auto a : s) {
					int ny = i + dy[a];
					int nx = j + dx[a];

					if (ny < 0 || ny >= R || nx < 0 || nx >= C)
						continue;
					check[ny][nx] = true;
				}
			}
		}
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (check[i][j] == true && map[i][j] == '.') {
				for (int k = 0; k < 7; ++k) {
					map[i][j] = dir[k];
					int tdir = -1;
					
					for (int t = 0; t < 4; ++t) {			// 시작지점의 첫 방향 설정
						int ty = start.first + dy[t];
						int tx = start.second + dx[t];
						
						if (ty < 0 || ty >= R || tx < 0 || tx >= C || map[ty][tx]=='.')
							continue;

						if (m.at(map[ty][tx]).count((t + 6) % 4) != 0)
							tdir = t; break;
					}

					if (tdir == -1)		// 방향을 못잡았을 경우
						continue;

					queue<info> q;
					q.push({start.first,start.second,tdir});
					while (!q.empty()) {
						int cy = q.front().y;
						int cx = q.front().x;
						int cdir = q.front().dir;
						q.pop();

						if (cy == end.first && cx == end.second) {			// 도착
							cout << i + 1 << " " << j + 1 << " " << dir[k];
							return 0;
						}

						int ny = cy + dy[cdir];
						int nx = cx + dx[cdir];
						int ndir = cdir;

						if (ny < 0 || ny >= R || nx < 0 || nx >= C || map[ny][nx] == '.')		// 실패
							break;
						if ((ndir == 0 || ndir == 2) && map[ny][nx] == '|')
							break;
						if ((ndir == 1 || ndir == 3) && map[ny][nx] == '-')
							break;

						if (map[ny][nx] == '1' || map[ny][nx] == '2' || map[ny][nx] == '3' || map[ny][nx] == '4') {
							// 방향 재설정
							int idir = (ndir + 6) % 4;
							if (m.at(map[ny][nx]).count(idir) == 0) {
								break;
							}
							for (int a : m.at(map[ny][nx])) {
								if (a != idir) {
									ndir = a;
									break;
								}
							}
						}
						q.push({ny,nx,ndir});
					}
				}
				return 0;
			}
		}
	}

	return 0;
}