#include <iostream>
#include <algorithm>
using namespace std;

int bj_12865() {
	int dp[100001] = {0,}; //가방의 용량이 w 까지일 때의 최대 가치합

	int N, K, w, v;
	cin >> N >> K;
	while (N--) {
		cin >> w >> v;
		for (int i = K; i >= w; i--)
			dp[i] = max(dp[i], dp[i - w] + v);
	}
	cout << dp[K] << '\n';
	return 0;
}