#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;

int arr[1001];
int dp[3][1001][31];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int t, w;
	cin >> t >> w;

	for (int i = 1; i <= t; ++i)
		cin >> arr[i];

	for (int i = 1; i <= t; ++i) {
		for (int j = 1; j <= w + 1; ++j) {
			if (arr[i] == 1) {
				dp[1][i][j] = max(dp[1][i - 1][j] + 1, dp[2][i - 1][j - 1] + 1);
				dp[2][i][j] = max(dp[1][i - 1][j - 1], dp[2][i - 1][j]);
			}
			else {
				if (i == 1 && j == 1)
					continue;
				dp[1][i][j] = max(dp[2][i - 1][j-1], dp[1][i - 1][j]);
				dp[2][i][j] = max(dp[1][i - 1][j - 1] + 1, dp[2][i - 1][j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= w + 1; ++i)
		ans = max(ans, max(dp[1][t][i], dp[2][t][i]));

	cout << ans;
	return 0;
}