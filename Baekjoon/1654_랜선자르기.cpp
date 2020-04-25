#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

bool lan(int mid,int k) {
	int ret = 0;
	for (auto a : v)
		ret += a / mid;

	if (ret >= k)
		return true;
	return false;
}

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		long long num;
		cin >> num;
		v.push_back(num);
	}

	long long low = 1, ans = 0, mid = 0;
	long long high = *max_element(v.begin(), v.end());

	while (low <= high) {
		mid = (low + high) >> 1;
		if (lan(mid, k)) {
			if (ans < mid)
				ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	 
	cout << ans;
	return 0;
}