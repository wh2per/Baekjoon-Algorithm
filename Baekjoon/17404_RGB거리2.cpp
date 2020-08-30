#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int dp[1001][3];
int arr[1001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int n;
	int ans = 1000 * 1000 + 1;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	for (int i = 0; i < 3; ++i) {			// 0번째, 1번째, 2번째 각각한번씩 진행
		for (int j = 0; j < 3; ++j) {
			if (i == j)
				dp[1][j] = arr[1][j];
			else
				dp[1][j] = 1000 * 1000 + 1;
		}

		for (int k = 2; k <= n; ++k) {
			dp[k][0] = arr[k][0] + min(dp[k - 1][1], dp[k - 1][2]);
			dp[k][1] = arr[k][1] + min(dp[k - 1][0], dp[k - 1][2]);
			dp[k][2] = arr[k][2] + min(dp[k - 1][0], dp[k - 1][1]);
		}

		for (int k = 0; k < 3; ++k) {		// 첫 집과 같은 색은 제외
			if (i != k)
				ans = min(ans, dp[n][k]);
		}
	}

	cout << ans;
	return 0;
}