#include <iostream>
#include <algorithm>
using namespace std;

int memory[101];
int cost[101];
int dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> memory[i];

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> cost[i];
		sum += cost[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = sum; j >= cost[i]; --j)
			dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]); //현재 cost에서 최대로 확보할수있는 메모리
	}

	int ans;
	for (ans = 0; ans < sum, dp[ans] < m; ++ans);
	cout << ans << endl;

	return 0;
}