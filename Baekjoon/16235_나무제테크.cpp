#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int dx[] = {1,1,0,-1,-1,-1,0,1};		// 오른쪽 부터 시계방향
const int dy[] = {0,1,1,1,0,-1,-1,-1};

struct info_tree {
	int y;
	int x;
	int count;
};

int map_tree[11][11];
int A[11][11];
vector<int> tree[11][11];

int bj_16235() {
	int N, M, K;
	cin >> N >> M >> K;
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
			map_tree[i][j] = 5;
		}
	}

	for (int i = 0; i < M; ++i) {
		int y, x, count;
		cin >> y >> x >> count;
		tree[y-1][x-1].push_back(count);
	}

	for (int z = 0; z < K; ++z) {
		// 봄 + 여름
		for (int i = 0; i <= N; ++i) {
			for (int j = 0; j <= N; ++j) {
				if (tree[i][j].size() == 0)
					continue;
				int die_energy = 0;
				vector<int> temp;

				sort(tree[i][j].begin(), tree[i][j].end());		// 가장 어린 나이 나무 채택
				for (int k = 0; k < tree[i][j].size(); ++k) {
					int age = tree[i][j][k];
					if (map_tree[i][j] >= age) {
						map_tree[i][j] -= age;
						temp.push_back(age + 1);
					}
					else
						die_energy += age / 2;
				}

				tree[i][j].clear();
				for (int k = 0; k < temp.size(); ++k)
					tree[i][j].push_back(temp[k]);
				map_tree[i][j] += die_energy;
			}
		}

		// 가을
		for (int i = 0; i <= N; ++i) {
			for (int j = 0; j <= N; ++j) {
				if (tree[i][j].size() == 0)
					continue;
				for (int k = 0; k < tree[i][j].size(); ++k) {
					int age = tree[i][j][k];
					if (age % 5 == 0) {
						for (int e = 0; e < 8; ++e) {
							int ny = i + dy[e];
							int nx = j + dx[e];

							if (ny < 0 || ny >= N || nx < 0 || nx >= N)
								continue;
							tree[ny][nx].push_back(1);
						}
					}
				}
			}
		}

		// 겨울
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j)
				map_tree[i][j] += A[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			ans += tree[i][j].size();
	}
	cout << ans;
	return 0;
}