#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

vector<vector<pair<int,int>>> tree;
vector<vector<int>> parent;
vector<vector<long long>> cost;
vector<int> depth;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int ds = (int)ceil(log2(n)); // MAX_NODE에 log2를 씌어 내림을 해준다.
	tree.assign(n + 1, vector<pair<int, int>>());
	parent.assign(n + 1, vector<int>(ds, 0));
	cost.assign(n + 1, vector<long long>(ds, 0));
	depth.assign(n + 1, -1);

	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;

		tree[u].push_back({ v,w });
		tree[v].push_back({ u,w });
	}
	dfs(1, 0);			// root 노드를 1로 지정

	for (int j = 1; j < ds; ++j) {
		for (int i = 1; i <= n; ++i) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];		// parent[i][j] = i의 2^j번째 부모번호를 저장
			if(cost[parent[i][j - 1]][j - 1] !=0)
				cost[i][j] = cost[i][j-1] + cost[parent[i][j-1]][j-1];				// cost[i][j] = i의 2^j번째 부모에 가는 비용을 저장
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {			// 경로 비용 출력
			long long ans = 0;
			cin >> b >> c;

			if (depth[b] < depth[c])
				swap(b, c);
			int diff = depth[b] - depth[c];
			for (int j = 0; diff; j++) {		// 깊이 차이만큼 반복
				if (diff % 2) {					// 홀수이면 diff/2 할때 0.5가 버려지므로 부모로 한번 더 가야함	 
					ans += cost[b][j];			// 현재까지 오는데 걸렸던 비용 더하기
					b = parent[b][j];
				}
				diff /= 2;						// 깊이를 반으로 줄이고 j를 증가시켜 부모로 가기
			}

			if (b != c) {		// 부모가 같지 않으면
				for (int j = ds - 1; j >= 0; --j) {
					if (parent[b][j] != 0 && parent[b][j] != parent[c][j]) {		// 부모가 있으면서 공통부모가 아니면
						ans += cost[b][j];
						ans += cost[c][j];
						b = parent[b][j];			// 부모로 이동
						c = parent[c][j];
					}
				}
				ans += cost[b][0];
				ans += cost[c][0];
			}
			cout << ans << "\n";
		}
		else {					// d번째 정점 출력
			cin >> b >> c >> d;
			int u = b, v = c;
			int ans = 0;

			if (depth[b] < depth[c])
				swap(b, c);
			int diff = depth[b] - depth[c];
			for (int j = 0; diff; j++) {		// 깊이 차이만큼 반복
				if (diff % 2) 					// 홀수이면 diff/2 할때 0.5가 버려지므로 부모로 한번 더 가야함	 
					b = parent[b][j];
				diff /= 2;						// 깊이를 반으로 줄이고 j를 증가시켜 부모로 가기
			}

			if (b != c) {		// 부모가 같지 않으면
				for (int j = ds - 1; j >= 0; --j) {
					if (parent[b][j] != 0 && parent[b][j] != parent[c][j]) {		// 부모가 있으면서 공통부모가 아니면
						b = parent[b][j];			// 부모로 이동
						c = parent[c][j];
					}
				}
				b = parent[b][0];
			}

			int db = depth[u] - depth[b];		// 출발점과 lca의 depth차
			if (db >= d-1) {						// d만큼 u에서 올라가기
				--d;
				for (int j = 0; d; j++) {
					if (d % 2)
						u = parent[u][j];
					d /= 2;
				}
				ans = u;
			}
			else {
				int dc = d - db - 1; 		// 남은 차이 dc만큼 lca에서 내려가야함 = depth[v]-depth[b]-dc 만큼 v에서 올라가기 
				dc = depth[v] - depth[b] - dc;
				for (int j = 0; dc; j++) {
					if (dc % 2)
						v = parent[v][j];
					dc /= 2;
				}
				ans = v;
			}
			cout << ans << "\n";
		}
	}

	return 0;
}