#include <iostream>
#define MAX 987654321
using namespace std;
#pragma warning(disable: 4996)

int N;
int color_val[1000][3];
int mini_val[1000][3];
int mini = MAX;

void dfs(int level, int nowNum, int sum) {
	// 합이 최소값보다 크면 종료 
	if (sum > mini) return;

	// 끝에 도달하면 종료
	if (level == N) {
		if (sum < mini) mini = sum;
		return;
	}

	for (int i = 0; i < 3; i++) {
		// 색이 같으면 그냥 넘겨 
		if (i == nowNum) continue;

		// 방문한 곳의 값이 더 작거나 같으면 종료 
		if ((mini_val[level][i] <= sum + color_val[level][i])) continue;
		else mini_val[level][i] = sum + color_val[level][i];

		// 다음 단계 
		dfs(level + 1, i, mini_val[level][i]);
	}
}

int bj_1149() {
	// 숫자 입력 받기 
	cin >> N;
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < 3; i++) {
			scanf("%d", &color_val[k][i]);
			mini_val[k][i] = MAX;
		}
	}

	for (int i = 0; i < 3; i++) {
		mini_val[0][i] = color_val[0][i];
	}
	for (int i = 0; i < 3; i++) {
		dfs(1, i, color_val[0][i]);
	}

	cout << mini;

	return 0;
}
