#include <iostream>
#include <climits>
#include <string.h>
#include <algorithm>
using namespace std;

int arr[16][16];
int dp[16][1 << 16];
int n, psize, on;

int bitmaskDP(int curr, int state) {
	if (curr >= psize)
		return 0;

	int& ret = dp[curr][state];
	if (ret != -1)
		return ret;

	ret = 987654321;
	for (int i = 0; i < n; ++i) {
		if (state & (1 << i)) {
			for (int j = 0; j < n; ++j) {
				if (i == j || state & (1 << j))
					continue;
				ret = min(ret, bitmaskDP(curr + 1, state | (1 << j)) + arr[i][j]);
			}
		}
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];
	}

	int state = 0;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		if (c == 'Y') {
			++on;
			state |= 1 << i;
		}
	}

	cin >> psize;
	int ans = bitmaskDP(on, state);
	if (ans == 987654321)
		cout << -1;
	else
		cout << ans;
	return 0;
}