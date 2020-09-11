#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;
	dp[1] = 1;

	for (int i = 1; i <= n; ++i) {
		int num;
		cin >> num;

		if (dp[i] == 0)
			continue;

		for (int j = 1; j <= num && i + j <= 1000; ++j) {
			if (dp[i + j] > dp[i] + 1 || dp[i + j] == 0)
				dp[i + j] = dp[i] + 1;
		}
	}


	if (dp[n] == 0)
		cout << -1;
	else
		cout << dp[n] - 1;

	return 0;
}