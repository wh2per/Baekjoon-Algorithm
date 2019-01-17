#include <iostream>
#include <algorithm>
using namespace std;

int a[101][101];
long long d[101][101];

int bj_1890() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	d[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= i; k++) {	//세로 검사
				if (i == n && k == n)
					continue;
				if (a[k][j] == i - k) {
					d[i][j] += d[k][j];
				}
			}

			for (int k = 1; k <= j; k++) {	//가로 검사
				if (j == n && k == n)
					continue;
				if (a[i][k] == j - k) {
					d[i][j] += d[i][k];
				}
			}
		}
	}



	cout << d[n][n];

	return 0;
}