#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
vector<vector<long long>> dp;

long long bf(int index, int sum) {
	// base case : 현재 마지막 숫자까지 도달했다면 결과 리턴
	if (index == n - 1)
		return (sum == v[n - 1]) ? 1 : 0;

	// 메모이제이션
	long long& ret = dp[index][sum];
	if (ret != -1)
		return ret;

	ret = 0;
	// 덧셈할 경우
	if (sum + v[index] <= 20)
		ret += bf(index + 1, sum + v[index]);
	// 뺄셈할 경우
	if (sum - v[index] >= 0)
		ret += bf(index + 1, sum - v[index]);

	return ret;
}

int main() {
	scanf("%d", &n);
	v.assign(n, 0);
	dp.assign(100, vector<long long>(21, -1));
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
	long long ans = bf(1, v[0]);
	printf("%lld", ans);

	return 0;
}