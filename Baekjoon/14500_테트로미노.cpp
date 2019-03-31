#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int bj_14500() {
	int ans = INT_MIN;
	int N, M;
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> map[i][j];
	}

	// 짝대기 ㅡ
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M - 3; ++j) {
			int temp = 0;
			temp += map[i][j];
			temp += map[i][j+1];
			temp += map[i][j+2];
			temp += map[i][j+3];
			if (temp > ans)
				ans = temp;
		}
	}

	// 짝대기 ㅣ
	for (int i = 0; i < N-3; ++i) {
		for (int j = 0; j < M; ++j) {
			int temp = 0;
			temp += map[i][j];
			temp += map[i+1][j];
			temp += map[i+2][j];
			temp += map[i+3][j];
			if (temp > ans)
				ans = temp;
		}
	}

	// 네모 ㅁ
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			int temp = 0;
			temp += map[i][j];
			temp += map[i][j+1];
			temp += map[i + 1][j];
			temp += map[i + 1][j+1];
			if (temp > ans)
				ans = temp;
		}
	}

	// 니은 1
	for (int i = 0; i < N - 2; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			int temp = 0;
			temp += map[i][j];
			temp += map[i + 1][j];
			temp += map[i + 2][j];
			temp += map[i + 2][j+1];
			if (temp > ans)
				ans = temp;
		}
	}

	// 니은 2
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < M - 2; ++j) {
			int temp = 0;
			temp += map[i][j];
			temp += map[i][j+1];
			temp += map[i][j+2];
			temp += map[i+1][j];
			if (temp > ans)
				ans = temp;
		}
	}

	// 니은 3
	for (int i = 0; i < N - 2; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			int temp = 0;
			temp += map[i][j];
			temp += map[i][j+1];
			temp += map[i+1][j + 1];
			temp += map[i+2][j + 1];
			if (temp > ans)
				ans = temp;
		}
	}

	// 니은 4
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < M - 2; ++j) {
			int temp = 0;
			temp += map[i][j+2];
			temp += map[i+1][j];
			temp += map[i + 1][j+1];
			temp += map[i + 1][j + 2];
			if (temp > ans)
				ans = temp;
		}
	}

	// 니은 대칭 1
	for (int i = 0; i < N - 2; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			int temp = 0;
			temp += map[i][j+1];
			temp += map[i + 1][j+1];
			temp += map[i + 2][j+1];
			temp += map[i +2][j];
			if (temp > ans)
				ans = temp;
		}
	}

	// 니은 대칭 2
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < M - 2; ++j) {
			int temp = 0;
			temp += map[i][j];
			temp += map[i + 1][j];
			temp += map[i + 1][j + 1];
			temp += map[i + 1][j+2];
			if (temp > ans)
				ans = temp;
		}
	}       
	
	// 니은 대칭 3
	for (int i = 0; i < N - 2; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			int temp = 0;
			temp += map[i][j];
			temp += map[i][j+1];
			temp += map[i + 1][j];
			temp += map[i + 2][j];
			if (temp > ans)
				ans = temp;
		}
	}

	// 니은 대칭 4
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < M - 2; ++j) {
			int temp = 0;
			temp += map[i][j];
			temp += map[i][j + 1];
			temp += map[i][j + 2];
			temp += map[i + 1][j +2];
			if (temp > ans)
				ans = temp;
		}
	}

	// 번개 1
	for (int i = 0; i < N - 2; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			int temp = 0;
			temp += map[i][j];
			temp += map[i+1][j];
			temp += map[i+1][j + 1];
			temp += map[i + 2][j + 1];
			if (temp > ans)
				ans = temp;
		}
	}

	// 번개 2
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < M - 2; ++j) {
			int temp = 0;
			temp += map[i + 1][j];
			temp += map[i + 1][j+1];
			temp += map[i][j + 1];
			temp += map[i][j + 2];
			if (temp > ans)
				ans = temp;
		}
	}

	// 번개 대칭 1
	for (int i = 0; i < N - 2; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			int temp = 0;
			temp += map[i][j+1];
			temp += map[i + 1][j+1];
			temp += map[i + 1][j];
			temp += map[i + 2][j];
			if (temp > ans)
				ans = temp;
		}
	}

	// 번개 대칭 2
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < M - 2; ++j) {
			int temp = 0;
			temp += map[i][j];
			temp += map[i][j + 1];
			temp += map[i+1][j + 1];
			temp += map[i+1][j + 2];
			if (temp > ans)
				ans = temp;
		}
	}

	// ㅗ 1
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < M - 2; ++j) {
			int temp = 0;
			temp += map[i][j+1];
			temp += map[i+1][j];
			temp += map[i+1][j + 1];
			temp += map[i+1][j + 2];
			if (temp > ans)
				ans = temp;
		}
	}

	// ㅗ 2
	for (int i = 0; i < N - 2; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			int temp = 0;
			temp += map[i][j];
			temp += map[i + 1][j];
			temp += map[i + 2][j];
			temp += map[i + 1][j+1];
			if (temp > ans)
				ans = temp;
		}
	}

	// ㅗ 3
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < M - 2; ++j) {
			int temp = 0;
			temp += map[i+1][j + 1];
			temp += map[i][j];
			temp += map[i][j + 1];
			temp += map[i][j + 2];
			if (temp > ans)
				ans = temp;
		}
	}

	// ㅗ 4
	for (int i = 0; i < N - 2; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			int temp = 0;
			temp += map[i+1][j];
			temp += map[i][j+1];
			temp += map[i + 1][j+1];
			temp += map[i + 2][j+1];
			if (temp > ans)
				ans = temp;
		}
	}

	cout << ans;
	
	return 0;
}