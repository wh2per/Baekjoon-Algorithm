#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <queue>
using namespace std;

const int dx[] = { 1,0, -1,0};		// 오른 - 아래 - 왼 - 위
const int dy[] = { 0,1,0, -1};

int bj_16234() {
	int flag = true;
	int move_ans = 0;
	int N, L, R;
	cin >> N >> L >> R;
	vector<vector<int>> world(N, vector<int>(N, 0));
	queue<pair<int, int> > q;
	queue<pair<int, int> > terr;
	
	for (int i = 0; i < N; ++i) {			// 맵 입력
		for (int j = 0; j < N; ++j)
			cin >> world[i][j];
	}

	while (flag) {
		vector<vector<bool>> check(N, vector<bool>(N, false));
		flag = false;
		move_ans++;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (check[i][j])					
					continue;
				q.push(make_pair(i,j));				// 기준점 저장
				terr.push(make_pair(i,j));			// 영역 저장
				check[i][j] = true;
				int population = world[i][j];

				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {		// 기준점 기준으로 4방향 검사
						int ty = y + dy[k];
						int tx = x + dx[k];
						if(ty<0 || ty>=N || tx<0 || tx>=N || check[ty][tx])		// 범위를 벗어나면, 검사한곳이라면 pass
							continue;
						if (abs(world[y][x] - world[ty][tx]) < L || abs(world[y][x] - world[ty][tx]) > R)		// 인구차이가 안맞으면 pass
							continue;
						flag = true;		// 인구이동 있음
						population += world[ty][tx];
						check[ty][tx] = true;
						q.push(make_pair(ty, tx));			// 새로운 기준점 저장
						terr.push(make_pair(ty, tx));		// 영역에 추가
					}
				}

				int new_p = population / terr.size();

				while (!terr.empty()) {				// 이번 영역에 해당 지역 인구 이동 시키기
					int ny = terr.front().first;
					int nx = terr.front().second;
					terr.pop();
					world[ny][nx] = new_p;
				}
			}
		}
	}

	cout << move_ans-1;
	return 0;
}