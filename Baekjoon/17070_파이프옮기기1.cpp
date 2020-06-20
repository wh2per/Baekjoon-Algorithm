#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

const int dx[] = { 1,0,1};
const int dy[] = { 0,1,1 };
const int MAX = 16;

int N;
int ans;
int arr[MAX][MAX];

void brute_force(int y, int x, int p) {
	if (y == N - 1 && x == N - 1) {
		++ans;
		return;
	}

	for (int i = 0; i < 3; ++i) {
		if ((i == 0 && p == 1) || (i == 1 && p == 0))		// 가로->세로, 세로->가로 X
			continue;

		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny >= N || nx >= N || arr[ny][nx] == 1)		// 범위 초과, 벽 
			continue;

		if (i == 2 && (arr[y][x + 1]==1 || arr[y + 1][x] == 1))			// 대각선일 경우
			continue;

		brute_force(ny, nx, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> arr[i][j];
	}

	brute_force(0, 1, 0);

	cout << ans;

	return 0;
}