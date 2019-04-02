#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int dx[] = { 0,1,0,-1 };
const int dy[] = {1,0,-1,0};

int bj_2468() {
	int ans = 1;
	int max =1;
	int min = 101;
	int N;
	cin >> N;
	vector<vector<int>> map(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {			// 맵 입력
		for (int j = 0; j < N; ++j) {
			int t;
			cin >> t;
			map[i][j] = t;
			if (max < t)
				max = t;
			if (min > t)
				min = t;
		}
	}

	for (int k = min; k <= max; ++k) {			// 물높이를 min~max까지 올려보며 검사
		vector<vector<bool>> check(N, vector<bool>(N, false));
		int temp_ans=0;

		for (int i = 0; i < N; ++i) {			
			for (int j = 0; j < N; ++j) {
				if (map[i][j] > k && !check[i][j]) {			// 물높이보다 높으면서 안가본곳
					queue<pair<int, int>> q;
					q.push({i,j});
					check[i][j] = true;
					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						q.pop();

						for (int h = 0; h < 4; ++h) {
							int ny = y + dy[h];
							int nx = x + dx[h];
							if (ny < 0 || ny >= N || nx < 0 || nx >= N)
								continue;
							if (map[ny][nx] > k && !check[ny][nx]) {
								check[ny][nx] = true;
								q.push({ ny,nx });
							}
						}
					}
					++temp_ans;
				}
			}
		}

		if (ans < temp_ans)
			ans = temp_ans;
	}

	cout << ans;
	return 0;
}