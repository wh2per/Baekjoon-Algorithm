#include <iostream>
#include <vector>
using namespace std;

int ans_2048;
int N_2048;

struct BOARD {
	int map[20][20];

	void rotate() {					// 오른쪽으로 90도 회전
		int temp[20][20];			

		for (int y = 0; y < N_2048; ++y) {
			for (int x = 0; x < N_2048; ++x) {
				temp[y][x] = map[N_2048 - x - 1][y];
			}
		}

		for (int y = 0; y < N_2048; ++y) {
			for (int x = 0; x < N_2048; ++x) {
				map[y][x] = temp[y][x];
			}
		}
	}

	int get_max() {					// 최대값 탐색
		int ret = 0;
		for (int y = 0; y < N_2048; ++y) {
			for (int x = 0; x < N_2048; ++x) {
				if (ret < map[y][x]) {
					ret = map[y][x];
				}
			}
		}
		return ret;
	}

	void up() {					// 위로 밀기
		int temp[20][20] = {0,};

		for (int x = 0; x < N_2048; ++x) {					// 왼쪽에서 오른쪽 열 순으로 
			int flag = 0;			// 연속으로 합쳐지기 방지
			int target = -1;		// 이동 pos
			for (int y = 0; y < N_2048; ++y) {				// 위쪽에서 아래쪽 행 순으로 검사
				if (map[y][x] == 0) 
					continue;
				
				if (flag == 1 && map[y][x] == temp[target][x]) {		// 나와 같은 값 & 합쳐진적 없음
					temp[target][x] *= 2;
					flag = 0;
				}
				else {
					temp[++target][x] = map[y][x];						// 나와 다른값 | 합쳐진적 있음
					flag = 1;									
				}
			}

			for (++target; target < N_2048; ++target) {			// 끝까지 돌지 않았을 경우를 대비
				temp[target][x] = 0;
			}
		}
	}
};

void dfs_2048(BOARD cur, int count) {
	if (count == 5) {
		int candi = cur.get_max();
		if (ans_2048< candi) {
			ans_2048 = candi;
		}
		return;
	}

	for (int dir = 0; dir < 4; ++dir) {
		BOARD next = cur;
		next.up();
		dfs_2048(next, count + 1);
		cur.rotate();
	}
}

int bj_12100() {
	ans_2048 = -1;

	BOARD board;
	cin >> N_2048;

	for (int i = 0; i < N_2048; i++) {				// map 입력
		for (int j = 0; j < N_2048; j++)
			cin >> board.map[i][j];
	}

	dfs_2048(board, 0);

	cout << ans_2048;

	return 0;
}