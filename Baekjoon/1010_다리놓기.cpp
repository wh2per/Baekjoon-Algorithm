#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <climits>
using namespace std;

int dp[31][31];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	
	int t;
	cin >> t;

	while (t--) {
		memset(dp, 0, sizeof(dp));
		int n, m;
		cin >> n >> m;

		for (int i = 0; i <= m; ++i)
			dp[1][i] = i;
		for (int i = 2; i <= n; ++i) {
			for (int j = i; j <= m; ++j) {
				for (int k = j; k >= i; --k)
					dp[i][j] += dp[i - 1][k - 1];
			}
		}

		cout << dp[n][m] << endl;
	}


	return 0;
}