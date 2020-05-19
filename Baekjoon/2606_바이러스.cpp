#include <iostream>
#include <queue>
using namespace std;

int v[101][101];
bool check[101];
queue<int> q;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;

		v[a][b] = 1;
		v[b][a] = 1;
	}

	q.push(1);

	while (!q.empty()) {
		int c = q.front();
		q.pop();

		check[c] = true;
		for (int i = 1; i <= n; ++i) {
			if (v[c][i] == 1 && !check[i])
				q.push(i);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (check[i])
			++ans;
	}

	cout << ans - 1;
	return 0;
}