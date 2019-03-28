#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int dx[] = {1,1,0,-1,-1,-1,0,1};		// 오른쪽 부터 시계방향
const int dy[] = {0,1,1,1,0,-1,-1,-1};

int bj_16235() {
	int tree_ans = 0;
	map<pair<int, int>, vector<int>> tree;
	map<pair<int, int>, vector<int>> dead;
	int N, M, K, x, y, z;

	cin >> N >> M >> K;
	vector<vector<int>> map(N, vector<int>(N, 5));
	vector<vector<int>> A(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i) {			// 맵 입력
		for (int j = 0; j < N; ++j)
			cin >> A[i][j];
	}

	for (int i = 0; i < M; i++) {		// 나무 입력
		cin >> x >> y >> z;
		if (tree.count({ x - 1,y - 1 }) > 0)				// (1,1)부터 시작
			tree[{x - 1, y - 1}].push_back(z);
		else
			tree.insert({ { x - 1,y - 1 }, {z} });
	}


	for (int z = 0; z < K; ++z) {
		// 봄
		vector<pair<int, int>> temp;
		for (auto a : tree) {
			int ty = a.first.first;
			int tx = a.first.second;
			vector<int> t = a.second;
			bool flag = true;
			int idx = 0;

			sort(t.begin(), t.end());
			while (flag) {
				if (map[ty][tx] >= t[idx]) {		// 가장 어린 나무의 나이보다 양분이 같거나 많음
					map[ty][tx] -= t[idx];		// 양분먹고
					t[idx]++;					// 나이도 먹고
					idx++;
					if (idx >= t.size()) {
						tree[{ty, tx}] = t;
						flag = false;
					}
				}
				else {
					flag = false;
					if (idx == 0) {			// 가장 어린 나무였으면 모든 나무 죽음
						dead.insert(a);		// 죽은 나무에 추가
						temp.push_back({ ty,tx });
					}
					else {				// 일부 나무만 죽어야 할때
						int size = t.size();
						vector<int> d;
						for (int k = 0; k < size - idx; ++k) {
							d.push_back(t.back());
							t.pop_back();
						}
						dead.insert({ { ty,tx }, d });
						tree[{ty, tx}] = t;		// 해당 지역 나무 갱신
					}
				}
			}
		}
		for (int e = 0; e < temp.size(); ++e) 
			tree.erase({temp[e]});
		

		vector<pair<int,int>> temp2;
		// 여름
		for (auto a : dead) {			// 죽은 나무들 꺼내서
			int ty = a.first.first;
			int tx = a.first.second;
			temp2.push_back({ ty,tx });
			vector<int> d = a.second;
			for (int k = 0; k < d.size(); ++k)
				map[ty][tx] += d[k] / 2;
		}
		for (int e = 0; e < temp2.size(); ++e)
			dead.erase({ temp2[e] });

		vector<pair<int, int>> temp3;
		// 가을
		for (auto a : tree) {
			int ty = a.first.first;
			int tx = a.first.second;
			vector<int> t = a.second;

			for (int g = 0; g < t.size(); ++g) {
				if (t[g] % 5 == 0) {
					for (int k = 0; k < 8; ++k) {		// 8방향 검사
						int ky = ty + dy[k];
						int kx = tx + dx[k];

						if (ky<0 || ky>=N || kx<0 || kx>=N)		// 범위를 벗어나면 pass
							continue;

						temp3.push_back({ky,kx});
					}
				}
			}
		}
		for (int e = 0; e < temp3.size(); ++e) {
			if (tree.count(temp3[e]) == 0)
				tree.insert({ temp3[e],{1} });
			else
				tree[temp3[e]].push_back(1);
		}

		// 겨울
		for (int q = 0; q < N; ++q) {
			for (int w = 0; w < N; ++w)
				map[q][w] += A[q][w];
		}
	}

	for (auto a : tree) {
		tree_ans += a.second.size();
	}

	cout << tree_ans;

	return 0;
}