#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int n, m, v;
bool edge[1001][1001];
bool check[1001];

void bfs() {
	queue<int> q;
	q.push(v);

	while (!q.empty()) {
		int c = q.front();
		q.pop();

		if (check[c])
			continue;
		cout << c << " ";
		check[c] = true;
		for (int i = 1; i <= n; ++i) {
			if (edge[c][i] && !check[i])
				q.push(i);
		}
	}
}

void dfs(int v) {
	if (check[v])
		return;
	cout << v << " ";
	check[v] = true;
	for (int i = 1; i <= n; ++i) {
		if (edge[v][i] && !check[i])
			dfs(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m >> v;

	while (m--) {
		int a, b;
		cin >> a >> b;

		edge[a][b] = true;
		edge[b][a] = true;
	}

	memset(check, false, sizeof(check));
	dfs(v);
	cout << "\n";
	memset(check, false, sizeof(check));
	bfs();

	return 0;
}