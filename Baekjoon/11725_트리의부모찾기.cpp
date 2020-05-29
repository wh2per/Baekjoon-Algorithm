#include <iostream>
#include <vector>
using namespace std;

int n;
int parent[100001];
bool check[100001];
vector<int> tree[100001];

void dfs(int start) {
	check[start] = true;

	for (int i = 0; i < tree[start].size(); ++i) {
		int next = tree[start][i];

		if (!check[next]) {
			parent[next] = start;
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; ++i) {
		cout << parent[i] << "\n";
	}
	return 0;
}