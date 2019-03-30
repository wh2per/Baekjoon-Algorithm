#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bj_1300() {
	int ans = 0;
	int N, K;
	cin >>N >>K;

	int left = 1;
	int right = K;
	int mid;
	while (left <= right) {
		mid = (left + right) >> 1;		
		long long count = 0;
		for (int i = 1; i <= N; ++i)
			count += min(N,mid/i);
		if (count >= K) {
			right = mid - 1;
			ans = mid;
		}
		else
			left = mid + 1;
	}
	cout << ans;
	return 0;
}