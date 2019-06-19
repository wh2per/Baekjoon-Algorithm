#include <iostream>
using namespace std;

int ncr_d[1000][1000];
long long ncr(int n, int r) {
	if (ncr_d[n][r] > 0)
		return ncr_d[n][r];

	if (n == r || r == 0)
		return ncr_d[n][r] = 1;

	return ncr_d[n][r] = (ncr(n - 1, r - 1) + ncr(n - 1, r)) % 10007;
}

int bj_11501() {
	int n, r;
	cin >> n >> r;
	cout << ncr(n, r);
	return 0;
}