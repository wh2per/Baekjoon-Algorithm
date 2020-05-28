#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int dp[50001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;

	vector<int> v;
	for (int i = 1; i <= 223; ++i)
		v.push_back(i * i);

	for (int i = 2; i <= n; ++i) {
		int minNum = INT_MAX;

		for (int j = 0; v[j] <= i; ++j) {
			int diff = i - v[j];
			minNum = min(minNum, dp[diff]);
		}

		dp[i] = minNum + 1;
	}

	cout << dp[n];
	return 0;
}