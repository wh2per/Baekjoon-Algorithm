#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string.h>
using namespace std;

int dp[501][1<<4];

int bitdp(int n, char bit) {
	if (n < 0) return 0;
	if (n < 1) return bit == 0;
	int& r = dp[n][bit];
	if (r != -1) return r;

	r = 0;
	if (bit == 0) {
		r += bitdp(n - 1, 0);
		r += bitdp(n - 1, 3);
		r += bitdp(n - 1, 9);
		r += bitdp(n - 1, 12);
		r += bitdp(n - 2, 0);
	}
	if (bit == 3) {
		r += bitdp(n - 1, 0);
		r += bitdp(n - 1, 12);
	}
	if (bit == 6) {
		r += bitdp(n - 1, 9);
	}
	if (bit == 9) {
		r += bitdp(n - 1, 0);
		r += bitdp(n - 1, 6);
	}
	if (bit == 12) {
		r += bitdp(n - 1, 0);
		r += bitdp(n - 1, 3);
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int t, n;
	cin >> t;

	memset(dp, -1, sizeof(dp));

	while (t--) {
		int n;
		cin >> n;
		cout << bitdp(n,0)<<"\n";
	}

	return 0;
}