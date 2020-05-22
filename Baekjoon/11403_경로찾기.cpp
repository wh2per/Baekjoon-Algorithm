#include <iostream>
#include <cstring>
using namespace std;

int n;
int arr[101][101];
bool check[101][101];
bool visit[101];

void dfs(int s, int e, int g) {
	visit[e] = true;
	check[g][e] = true;

	for (int i = 1; i <= n; ++i) {
		if (arr[e][i] && !visit[i])
			dfs(e, i, g);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> arr[i][j];
			check[i][j] = arr[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (arr[i][j] != 0) {
				memset(visit, 0, sizeof(visit));
				dfs(i, j, i);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cout << check[i][j] << " ";
		cout << "\n";
	}

	return 0;
}