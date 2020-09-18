#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int N, M, K, cnt, ans;
bool visited[100][100];
int map[100][100];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

void dfs(int x, int y) {
    cnt++;
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < M && ny < N && !visited[ny][nx] && map[ny][nx]) 
            dfs(nx, ny);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        map[r - 1][c - 1] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                cnt = 0;
                dfs(j, i);
                if (cnt > ans) 
                    ans = cnt;
            }
        }
    }

    cout << ans;
	return 0;
}