#include <iostream>
#include <vector>
using namespace std;

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,-1,1};

int bj_14499() {
	int N, M, x,y, K;
	cin >> N >> M >> y >>x >> K;
	vector<vector<int>> map(N, vector<int>(M));
	vector<int> dice(6, 0);		// 위쪽, 오른쪽, 아래쪽, 왼쪽, 뒤쪽, 앞쪽

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> map[i][j];
	}
	
	for (int i = 0; i < K; ++i) {		// 오른쪽, 왼쪽, 위쪽, 아래쪽
		int move;
		cin >> move;

		int cy = y + dy[move-1];
		int cx = x + dx[move-1];
		if (cy < 0 || cy >= N || cx < 0 || cx >= M) 
			continue;
		y = cy;
		x = cx;

		if (move == 1) {			// 오른쪽
			int temp = dice[1];
			dice[1] = dice[0];		
			dice[0] = dice[3];
			dice[3] = dice[2];
			dice[2] = temp;
		}else if(move==2){			// 왼쪽
			int temp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[3];
			dice[3] = dice[0];
			dice[0] = temp;
		}
		else if (move == 3) {		// 위쪽
			int temp = dice[0];
			dice[0] = dice[5];
			dice[5] = dice[2];
			dice[2] = dice[4];
			dice[4] = temp;
		}
		else {						// 아래쪽
			int temp = dice[0];
			dice[0] = dice[4];
			dice[4] = dice[2];
			dice[2] = dice[5];
			dice[5] = temp;
		}

		if (map[y][x] == 0) {
			map[y][x] = dice[2];
		}
		else {
			dice[2] = map[y][x];
			map[y][x] = 0;
		}
		cout << dice[0] << '\n';
	}

	return 0;
}