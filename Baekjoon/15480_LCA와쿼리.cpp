#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int>> tree;
vector<vector<int>> parent;
vector<int> depth;
int ds;

void dfs(int now, int dpt) {
	depth[now] = dpt;

	for (auto a : tree[now]) {
		if (depth[a] == -1) {
			parent[a][0] = now;
			dfs(a, dpt + 1);
		}
	}
}

int lca(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);
	int diff = depth[u] - depth[v];
	for (int j = 0; diff; j++) {		// 깊이 차이만큼 반복
		if (diff % 2)
			u = parent[u][j];
		diff /= 2;
	}

	if (u != v) {		// 부모가 같지 않으면
		for (int j = ds - 1; j >= 0; --j) {
			if (parent[u][j] != 0 && parent[u][j] != parent[v][j]) {		// 부모가 있으면서 공통부모가 아니면
				u = parent[u][j];			// 부모로 이동
				v = parent[v][j];
			}
		}
		u = parent[u][0];
	}
	return u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	ds = (int)ceil(log2(n)); // MAX_NODE에 log2를 씌어 내림을 해준다.

	tree.assign(n + 1, vector<int>());
	depth.assign(n + 1, -1);
	parent.assign(n + 1, vector<int>(ds, 0));

	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;

		tree[y].push_back(x);
		tree[x].push_back(y);
	}
	dfs(1, 0);

	for (int j = 1; j < ds; ++j) {
		for (int i = 1; i <= n; ++i)
			parent[i][j] = parent[parent[i][j - 1]][j - 1];			// parent[i][j] = i의 2^j번째 부모 저장
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int r, u, v;
		cin >> r >> u >> v;

		int ans1 = lca(u, v);
		int ans2 = lca(r, v);
		int ans3 = lca(r, u);
		int ans = max(depth[ans1], max(depth[ans2], depth[ans3]));
		if (ans == depth[ans1])
			cout << ans1 << "\n";
		else if (ans == depth[ans2])
			cout << ans2 << "\n";
		else
			cout << ans3 << "\n";
	}

	return 0;
}