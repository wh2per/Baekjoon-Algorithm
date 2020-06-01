#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<pair<int, int>> edge[100001];
vector<bool> check;

int ans;
int endV;

void dfs(int start, int cost) {
	if (check[start])
		return;
	check[start] = true;

	if (ans < cost) {
		ans = cost;
		endV = start;
	}

	for (int i = 0; i < edge[start].size(); ++i)
		dfs(edge[start][i].first, cost + edge[start][i].second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v;
	cin >> v;

	for (int i = 0; i < v; ++i) {
		int s;
		cin >> s;

		while (1) {
			int e, c;
			cin >> e;
			if (e == -1)
				break;
			cin >> c;

			edge[s].push_back({ e,c });
		}
	}

	check.assign(v + 1, false);
	dfs(1, 0);
	check.assign(v + 1, false);
	dfs(endV, 0);

	cout << ans;

	return 0;
}