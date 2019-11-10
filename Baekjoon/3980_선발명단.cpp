#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string.h>
using namespace std;

int dp[11][1 << 11];
int arr[11][11];

int bitdp(int curr, int state) {
	if (curr == 11)
		return 0;
	
	int& ret = dp[curr][state];
	if (ret != -1)
		return ret;

	for (int i = 0; i < 11; ++i) {
		if (((state & (1 << i)) == 0) && arr[curr][i] != 0) {
			int sub = bitdp(curr + 1, state | 1 << i);
			if (sub != -1)
				ret = max(ret, sub + arr[curr][i]);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int c;
	cin >> c;
	while (c--) {
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < 11; ++i) {
			for (int j = 0; j < 11; ++j)
				cin >> arr[i][j];
		}
		cout << bitdp(0,0) << "\n";
	}

	return 0;
}