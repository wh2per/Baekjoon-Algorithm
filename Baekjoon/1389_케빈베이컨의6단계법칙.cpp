#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int graph[101][101];
int n, m;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = graph[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)
					continue;
				else if (graph[i][k] && graph[k][j]) {
					if (graph[i][j] == 0)
						graph[i][j] = graph[i][k] + graph[k][j];
					else
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
	}

	int max = INT_MAX;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int sum = 0;
		for (int j = 1; j <= n; ++j)
			sum += graph[i][j];
		if (max > sum) {
			max = sum;
			ans = i;
		}
	}

	cout << ans;

	return 0;
}

