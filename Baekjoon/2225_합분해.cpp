#include <iostream>
using namespace std;
long long d[201][201];
long long mod = 1000000000;
int bj_2225() {

	int n, k;
	cin >> n >> k;
	d[0][0] = 1LL;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 0; l <= j; l++) {
				d[i][j] += d[i - 1][j - l];
				d[i][j] %= mod;
			}
		}
	}
	long long ans;



	cout << d[k][n];

	return 0;
}