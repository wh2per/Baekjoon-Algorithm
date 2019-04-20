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

struct cmp_tree {
	bool operator()(info_tree& if1, info_tree& if2) {
		if (if1.count < if2.count)
			return true;
		else
			return false;
	}
};

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<int>> map_tree(N, vector<int>(N, 5));
	vector<vector<int>> A(N, vector<int>(N, 0));
	vector<info_tree> tree;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) 
			cin >> A[i][j];
	}

	for (int i = 0; i < M; ++i) {
		int y, x, count;
		cin >> y >> x >> count;
		tree.push_back({y-1,x-1,count});
	}

	for (int z = 0; z < K; ++z) {
		// 봄
		sort(tree.begin(), tree.end(), cmp_tree());
		vector<info_tree> tree_next;
		vector<info_tree> tree_dead;
		for (int i = 0; i < tree.size(); ++i) {
			int y = tree[i].y;
			int x = tree[i].x;
			int count = tree[i].count;

			if (count > map_tree[y][x])
				tree_dead.push_back(tree[i]);		// 죽은 나무 추가
			else {
				map_tree[y][x] -= count;
				++count;
				tree_next.push_back({ y,x,count });
			}
		}

		// 여름
		for (int i = 0; i < tree_dead.size(); ++i) {
			int y = tree_dead[i].y;
			int x = tree_dead[i].x;
			int count = tree_dead[i].count;

			map_tree[y][x] += count / 2;
		}

		// 가을
		int tsize = tree_next.size();
		for (int i = 0; i < tsize; ++i) {
			if (tree_next[i].count % 5 == 0) {		// 5의 배수
				int y = tree_next[i].y;
				int x = tree_next[i].x;
				for (int k = 0; k < 8; ++k) {
					int ny = y + dy[k];
					int nx = x + dx[k];

					if (ny < 0 || ny >= N || nx < 0 || nx >= N)
						continue;
					
					tree_next.push_back({ny,nx,1});
				}
			}
		}

		tree = tree_next;

		// 겨울
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j)
				map_tree[i][j] += A[i][j];
		}
	}

	cout << tree.size();

	return 0;
}