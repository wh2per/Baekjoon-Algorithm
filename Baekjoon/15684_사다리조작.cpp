#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int ans_ladder;

bool check_ladder(vector<vector<int>>& ladder, int N, int H) {
	for (int i = 1; i <= N; ++i) {
		int cx = i;
		for (int j = 1; j <= H; ++j) {
			if (ladder[j][cx] == 1) 
				++cx;
			else if (ladder[j][cx-1] == 1) 
				--cx;
		}
		if (cx != i)
			return false;
	}
	return true;
}

void dfs_ladder(vector<vector<int>>& ladder,int count, int y, int x,int N, int H) {
	if (count > ans_ladder)
		return;
	
	if (check_ladder(ladder, N, H)) {
		if (ans_ladder > count)
			ans_ladder = count;
		return;
	}
	
	if (count == 3)
		return;

	for (int i = y; i <= H; ++i) {
		for (int j = x; j < N; ++j) {
			if (ladder[i][j] == 0 && ladder[i][j - 1] == 0 && ladder[i][j + 1] == 0) {		// 사다리 놓을 수 있는지 검사
				ladder[i][j] = 1;
				dfs_ladder(ladder, count + 1, i, j, N, H);
				ladder[i][j] = 0;
			}
		}
		x = 1;
	}
}

int bj_15684() {
	ans_ladder = 4;
	int N, M, H;
	cin >> N >> M >> H;
	vector<vector<int>> ladder(H+1, vector<int>(N+1,0));		// 기본 '0'
	
	for (int i = 0; i<M; ++i) {					// 초기 사다리 세팅
		int y, x;
		cin >> y >> x;
		ladder[y][x] = 1;
	}

	dfs_ladder(ladder,0,1,1,N,H);
	
	if (ans_ladder == 4)
		ans_ladder = -1;

	cout << ans_ladder;
	return 0;
}