#include <iostream>
#define MAX 987654321
using namespace std;
#pragma warning(disable: 4996)

int N_1149;
int color_val_1149[1000][3];
int mini_val_1149[1000][3];
int mini_1149 = MAX;

void dfs(int level, int nowNum, int sum) {
	// 합이 최소값보다 크면 종료 
	if (sum > mini_1149) return;

	// 끝에 도달하면 종료
	if (level == N_1149) {
		if (sum < mini_1149) mini_1149 = sum;
		return;
	}

	for (int i = 0; i < 3; i++) {
		// 색이 같으면 그냥 넘겨 
		if (i == nowNum) continue;

		// 방문한 곳의 값이 더 작거나 같으면 종료 
		if ((mini_val_1149[level][i] <= sum + color_val_1149[level][i])) continue;
		else mini_val_1149[level][i] = sum + color_val_1149[level][i];

		// 다음 단계 
		dfs(level + 1, i, mini_val_1149[level][i]);
	}
}

int bj_1149() {
	// 숫자 입력 받기 
	cin >> N_1149;
	for (int k = 0; k < N_1149; k++) {
		for (int i = 0; i < 3; i++) {
			scanf("%d", &color_val_1149[k][i]);
			mini_val_1149[k][i] = MAX;
		}
	}

	for (int i = 0; i < 3; i++) {
		mini_val_1149[0][i] = color_val_1149[0][i];
	}
	for (int i = 0; i < 3; i++) {
		dfs(1, i, color_val_1149[0][i]);
	}

	cout << mini_1149;

	return 0;
}
