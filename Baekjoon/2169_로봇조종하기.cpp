#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int bj_2169() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> map(n, vector<int>(m));
	vector<vector<int>> dp(n, vector<int>(m,0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];
	}

	dp[0][0] = map[0][0];
	for (int j = 1; j < m; ++j)
		dp[0][j] += map[0][j] + dp[0][j - 1];
	
	for (int i = 1; i < n; ++i) {
		vector<int> temp1(m);
		vector<int> temp2(m);

		// 왼쪽에서 오른쪽으로
		temp1[0] = dp[i - 1][0] + map[i][0];
		for (int j = 1; j < m; ++j)
			temp1[j] = max(temp1[j-1], dp[i-1][j]) + map[i][j];

		// 오른쪽에서 왼쪽으로
		temp2[m - 1] = dp[i - 1][m - 1] + map[i][m - 1];
		for (int j = m - 2; j >= 0; --j)
			temp2[j] = max(temp2[j + 1], dp[i - 1][j]) + map[i][j];

		for (int j = 0; j < m; ++j)
			dp[i][j] = max(temp1[j], temp2[j]);
	}
	cout << dp[n - 1][m - 1];
	return 0;
}