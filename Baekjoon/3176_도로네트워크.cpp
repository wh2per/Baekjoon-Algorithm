#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<vector<pair<int,int>>> info;
int depth[100001];
bool visited[100001];
int parent[100001][20];		//노드 i의 2^j번째 조상
int maxd[100001][20];		//노드 i부터 2^j번째 조상까지의 간선 중 최대값
int mind[100001][20];		//노드 i부터 2^j번째 조상까지의 간선 중 최소값


void dfs(int now, int dpt) {
	depth[now] = dpt;
	visited[now] = true;

	for (auto a : info[now]) {
		int next = a.first; 
		int cost = a.second;
		if (!visited[next]) {
			parent[next][0] = now;
			maxd[next][0] = cost;
			mind[next][0] = cost;
			dfs(next, dpt + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	info.assign(n + 1, vector<pair<int, int>>());
	for (int i = 1; i < n; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		info[x].push_back({ y,c });
		info[y].push_back({ x,c });
	}

	dfs(1, 1);
	for (int j = 1; j < 20; ++j) {
		for (int i = 1; i <= n; ++i) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
			maxd[i][j] = max(maxd[i][j - 1], maxd[parent[i][j - 1]][j - 1]);
			mind[i][j] = min(mind[i][j - 1], mind[parent[i][j - 1]][j - 1]);
		}
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int u, v;
		cin >> u >> v;

		int minroad = INT_MAX;
		int maxroad = INT_MIN;

		if (depth[u] > depth[v]) 
			swap(u, v);
		for (int i = 19; i >= 0; i--)
		{
			if (depth[v] - depth[u] >= (1 << i))
			{
				maxroad = max(maxroad, maxd[v][i]);
				minroad = min(minroad, mind[v][i]);
				v = parent[v][i];
			}
		}
		if (u != v) {
			for (int i = 19; i >= 0; i--)
			{
				if (parent[u][i] != parent[v][i])
				{
					maxroad = max(maxroad, max(maxd[u][i], maxd[v][i]));
					minroad = min(minroad, min(mind[u][i], mind[v][i]));
					u = parent[u][i];
					v = parent[v][i];
				}
			}
			maxroad = max(maxroad, max(maxd[u][0], maxd[v][0]));
			minroad = min(minroad, min(mind[u][0], mind[v][0]));
		}
		
		cout << minroad << " "<< maxroad << "\n";
	}

	return 0;
}