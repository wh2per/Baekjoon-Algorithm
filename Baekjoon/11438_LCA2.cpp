#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100001];
int depth[100001];
bool visited[100001];
int parent[100001][20];

void dfs(int now, int dpt) {
	depth[now] = dpt;
	visited[now] = true;

	for (auto a : tree[now]) {
		if (!visited[a]) {
			parent[a][0] = now;
			dfs(a, dpt + 1);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int p, c;
		cin >> p >> c;
		tree[p].push_back(c);
		tree[c].push_back(p);
	}
	dfs(1,0);
	
	for (int j = 1; j < 20; ++j) {
		for (int i = 1; i <= n; ++i)
			parent[i][j] = parent[parent[i][j-1]][j-1];
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		if (depth[u] < depth[v])
			swap(u, v);
		int diff = depth[u] - depth[v];
		for (int j = 0; diff; j++) {
			if (diff % 2)
				u = parent[u][j];
			diff /= 2;
		}
		if (u != v) {
			for (int j = 19; j >= 0; --j) {
				if (parent[u][j] != parent[v][j]) {
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			u = parent[u][0];
		}
		cout << u << "\n";
	}

	return 0;
}