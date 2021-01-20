#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;

int dp[1000001];
int before[1000001];

int go(int n) {
	dp[1] = 0;
	before[1] = -1;

	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1;
		before[i] = i - 1;

		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			before[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			before[i] = i / 3;
		}
	}

	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;

	cout << go(n) << "\n";

	while (n != -1) {
		cout << n << ' ';
		n = before[n];
	}

	return 0;
}