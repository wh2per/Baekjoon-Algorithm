#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> tree;
vector<vector<long long>> cost;
vector<vector<int>> parent;
vector<int> depth;
int ds;

void dfs(int now, int dpt) {
	depth[now] = dpt;

	for (auto a : tree[now]) {
		if (depth[a.first] == -1) {
			parent[a.first][0] = now;			// 0번째는 부모를 저장
			cost[a.first][0] = a.second;
			dfs(a.first, dpt + 1);
		}
	}
}

int lca(int u, int v) {
	long long ans = 0;

	if (depth[u] < depth[v])
		swap(u, v);
	int diff = depth[u] - depth[v];
	for (int j = 0; diff; j++) {		// 깊이 차이만큼 반복
		if (diff % 2) {
			ans += cost[u][j];			// 현재까지 오는데 걸렸던 비용 더하기
			u = parent[u][j];
		}diff /= 2;
	}

	if (u != v) {		// 부모가 같지 않으면
		for (int j = ds - 1; j >= 0; --j) {
			if (parent[u][j] != 0 && parent[u][j] != parent[v][j]) {		// 부모가 있으면서 공통부모가 아니면
				ans += cost[u][j];
				ans += cost[v][j];
				u = parent[u][j];			// 부모로 이동
				v = parent[v][j];
			}
		}
		ans += cost[u][0];
		ans += cost[v][0];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	ds = (int)ceil(log2(n)); // MAX_NODE에 log2를 씌어 내림을 해준다.

	tree.assign(n + 1, vector<pair<int, int>>());
	depth.assign(n + 1, -1);
	parent.assign(n + 1, vector<int>(ds, 0));
	cost.assign(n + 1, vector<long long>(ds, 0));

	for (int i = 0; i < n - 1; ++i) {
		int x, y, z;
		cin >> x >> y >> z;

		tree[y].push_back({ x, z });
		tree[x].push_back({ y, z });
	}
	dfs(1, 0);

	for (int j = 1; j < ds; ++j) {
		for (int i = 1; i <= n; ++i) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];			// parent[i][j] = i의 2^j번째 부모 저장
			if (cost[parent[i][j - 1]][j - 1] != 0)
				cost[i][j] = cost[i][j - 1] + cost[parent[i][j - 1]][j - 1];				// cost[i][j] = i의 2^j번째 부모에 가는 비용을 저장
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << "\n";
	}

	return 0;
}