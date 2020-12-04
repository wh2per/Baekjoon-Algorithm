#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

long long dp[8];
long long path[8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	
	int n;
	cin >> n;

	dp[1] = 1;
	dp[3] = 1;

	for (int i = 2; i <= n; ++i) {
		path[0] = (dp[1] + dp[3]) % 1000000007;
		path[1] = (dp[0] + dp[2] + dp[3]) % 1000000007;
		path[2] = (dp[1] + dp[3] + dp[4] + dp[5]) % 1000000007;
		path[3] = (dp[0] + dp[1] + dp[2] + dp[5]) % 1000000007;
		path[4] = (dp[2] + dp[5] + dp[6]) % 1000000007;
		path[5] = (dp[2] + dp[3] + dp[4] + dp[7]) % 1000000007;
		path[6] = (dp[4] + dp[7]) % 1000000007;
		path[7] = (dp[5] + dp[6]) % 1000000007;

		for (int j = 0; j < 8; ++j)
			dp[j] = path[j];
	}

	cout << dp[0];

	return 0;
}