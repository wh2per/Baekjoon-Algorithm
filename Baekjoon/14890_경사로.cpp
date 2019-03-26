#include <iostream>
#include <vector>
using namespace std;

int bj_14890(){
	int ans=0;
	int N, L;
	cin >> N >> L;

	vector<vector<int>> map(N, vector<int>(N));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}

	// 가로 검사
	for (int i = 0; i < N; ++i) {
		int scount = 1;
		int j;
		for (j = 0; j < N-1; ++j) {
			if (map[i][j] == map[i][j + 1])
				++scount;			// 같은 높이가 얼마나 이어지는지 검사용
			else{
				if (abs(map[i][j] - map[i][j + 1]) > 1)		// 차이가 1층 이상나면 패스
					break;

				if (map[i][j + 1] < map[i][j]) {	// 현재보다 낮을 때
					int lcount=0;
					int k;
					for (k = j+1; k < j+1+L; ++k) {
						if (k<N && map[i][j+1] == map[i][k])
							++lcount;
						else
							break;
					}
					if (lcount < L)			// 아래층이 L보다 짧게 유지되면 패스
						break;
					else {					
						j = k - 2;
						scount = 0;
					}
				}
				else {			// 현재보다 높을 때
					if (scount < L)			// 현재층이 L보다 짧게 유지되면 패스
						break;
					else 
						scount = 1;
				}
			}
		}
		if (j == N-1)			// 끝까지 무사히 도착
			ans++;
	}

	// 세로 검사
	for (int i = 0; i < N; ++i) {
		int scount = 1;
		int j;
		for (j = 0; j < N - 1; ++j) {
			if (map[j][i] == map[j+1][i])
				++scount;			// 같은 높이가 얼마나 이어지는지 검사용
			else{
				if (abs(map[j][i] - map[j + 1][i]) > 1)		// 차이가 1층 이상나면 패스
					break;

				if (map[j + 1][i] < map[j][i]) {	// 현재보다 낮을 때
					int lcount = 0;
					int k;
					for (k = j+1; k < j+1 + L; ++k) {
						if (k<N && map[j+1][i] == map[k][i])
							++lcount;
						else
							break;
					}
					if (lcount < L)			// 아래층이 L보다 짧게 유지되면 패스
						break;
					else {
						j = k - 2;
						scount = 0;
					}
				}
				else {			// 현재보다 높을 때
					if (scount < L)			// 현재층이 L보다 짧게 유지되면 패스
						break;
					else 
						scount = 1;
				}
			}
		}
		if (j == N-1)			// 끝까지 무사히 도착
			ans++;
	}

	cout << ans;

	return 0;
}