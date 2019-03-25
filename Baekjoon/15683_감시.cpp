#include <iostream>
#include <vector>
#include <map>
using namespace std;

int cctv_N, cctv_M, cctv_count;
int cctv_ans;
vector<pair<int,pair<int,int>>> cctv;
const int dx[] = {1,0,-1,0};		// 오른쪽 위쪽 왼쪽 아래쪽 순서
const int dy[] = {0,-1,0,1};

void cctv_check(vector<vector<int>> &tmp, int cctv_num, int dir, int y, int x) {
	if (cctv_num == 1) {
		if (dir == 0 || dir == 2) {
			int tx = x + dx[dir];
			int ty = y;
			while (tx > -1 && tx<cctv_M && tmp[ty][tx] != 6) {	// 범위를 벗어나지 않으면서 벽이 아니면 체크
				tmp[ty][tx] = 7;
				tx += dx[dir];
			}
		}
		else {
			int tx = x;
			int ty = y + dy[dir];
			while (ty>-1 && ty < cctv_N && tmp[ty][tx] != 6) {	// 범위를 벗어나지 않으면서 벽이 아니면 체크
				tmp[ty][tx] = 7;
				ty += dy[dir];
			}
		}
	}
	else if (cctv_num == 2) {
		for (int i=0+dir; i < 4; i+=2) {			// 2방향
			if (i == 0 || i == 2) {
				int tx = x + dx[i];
				int ty = y;
				while (tx > -1 && tx < cctv_M && tmp[ty][tx] != 6) {	// 범위를 벗어나지 않으면서 벽이 아니면 체크
					tmp[ty][tx] = 7;
					tx += dx[i];
				}
			}
			else {
				int tx = x;
				int ty = y + dy[i];
				while (ty > -1 && ty < cctv_N && tmp[ty][tx] != 6) {	// 범위를 벗어나지 않으면서 벽이 아니면 체크
					tmp[ty][tx] = 7;
					ty += dy[i];
				}
			}
		}
	}
	else if (cctv_num == 3) {
		for (int i = 0; i < 4; i++) {			// 인접 2방향 제거
			if (i != dir && i != (dir + 1) % 4) {
				if (i == 0 || i == 2) {
					int tx = x + dx[i];
					int ty = y;
					while (tx > -1 && tx < cctv_M && tmp[ty][tx] != 6) {	// 범위를 벗어나지 않으면서 벽이 아니면 체크
						tmp[ty][tx] = 7;
						tx += dx[i];
					}
				}
				else {
					int tx = x;
					int ty = y + dy[i];
					while (ty > -1 && ty < cctv_N && tmp[ty][tx] != 6) {	// 범위를 벗어나지 않으면서 벽이 아니면 체크
						tmp[ty][tx] = 7;
						ty += dy[i];
					}
				}
			}
		}
	}
	else if (cctv_num == 4) {
		for (int i = 0; i < 4; i++) {
			if (dir != i) {			// 한방향 빼고 모두
				if (i == 0 || i == 2) {
					int tx = x + dx[i];
					int ty = y;
					while (tx > -1 && tx < cctv_M && tmp[ty][tx] != 6) {	// 범위를 벗어나지 않으면서 벽이 아니면 체크
						tmp[ty][tx] = 7;
						tx += dx[i];
					}
				}
				else {
					int tx = x;
					int ty = y + dy[i];
					while (ty > -1 && ty < cctv_N && tmp[ty][tx] != 6) {	// 범위를 벗어나지 않으면서 벽이 아니면 체크
						tmp[ty][tx] = 7;
						ty += dy[i];
					}
				}
			}
		}
	}
	else if (cctv_num == 5) {		
		for (int i = 0; i < 4; i++) {			// 4방향 모두
			if (i == 0 || i == 2) {
				int tx = x + dx[i];
				int ty = y;
				while (tx > -1 && tx < cctv_M && tmp[ty][tx] != 6) {	// 범위를 벗어나지 않으면서 벽이 아니면 체크
					tmp[ty][tx] = 7;
					tx += dx[i];
				}
			}
			else {
				int tx = x;
				int ty = y + dy[i];
				while (ty > -1 && ty < cctv_N && tmp[ty][tx] != 6) {	// 범위를 벗어나지 않으면서 벽이 아니면 체크
					tmp[ty][tx] = 7;
					ty += dy[i];
				}
			}
		}
	}
}

void cctv_dfs(vector<vector<int>> &map, int idx, int count) {
	if (count == 0) {
		// 사각지대 계산
		int temp_ans = 0;
		for (int i = 0; i < cctv_N; ++i) {		
			for (int j = 0; j < cctv_M; ++j) {
				if (map[i][j] == 0)
					++temp_ans;
			}
		}
		if (temp_ans < cctv_ans)
			cctv_ans = temp_ans;
		return;
	}

	int cdir;
	if (cctv[idx].first == 1 || cctv[idx].first == 3 || cctv[idx].first == 4)
		cdir = 4;
	else if (cctv[idx].first == 2)
		cdir = 2;
	else if (cctv[idx].first == 5)
		cdir = 1;
	
	for (int k = 0; k < cdir; k++) {
		vector<vector<int>> tmp(cctv_N, vector<int>(cctv_M));
		for (int i = 0; i < cctv_N; ++i) {		// 맵 복사
			for (int j = 0; j < cctv_M; ++j)
				tmp[i][j] = map[i][j];
		}

		cctv_check(tmp, cctv[idx].first, k, cctv[idx].second.first, cctv[idx].second.second);
		cctv_dfs(tmp, idx+1, count-1);
	}
}

int bj_15683() {
	cin >> cctv_N >> cctv_M;
	cctv_ans = cctv_N * cctv_M;
	vector<vector<int>> cctv_map(cctv_N, vector<int>(cctv_M));

	for (int i = 0; i < cctv_N; ++i) {		// 맵 입력
		for (int j = 0; j < cctv_M; ++j) {
			cin >> cctv_map[i][j];
			if (cctv_map[i][j] != 0 && cctv_map[i][j] != 6) {
				++cctv_count;
				cctv.push_back(make_pair(cctv_map[i][j],make_pair(i,j)));
			}
		}
	}

	cctv_dfs(cctv_map,0,cctv_count);
	
	cout << cctv_ans;
	return 0;
}