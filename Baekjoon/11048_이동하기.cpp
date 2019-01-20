#include <iostream>
#include <algorithm>
using namespace std;

int bj_11048() {
	int a[1001][1001];
	int d[1001][1001];
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = max(d[i - 1][j], d[i][j - 1]) + a[i][j];
		}
	}

	cout << d[n][m];

	return 0;
}