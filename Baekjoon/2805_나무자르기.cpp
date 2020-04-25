#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

long long cut(long long mid) {
	long long ret = 0;
	for (auto a : v) {
		long long temp = a - mid;
		if (temp > 0)
			ret += temp;
	}

	return ret;
}

int main() {
	long long n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	long long low = 0, high = *max_element(v.begin(), v.end()), mid = 0;
	long long ans = 0;
	
	while (low<=high) {
		mid = (low + high) >> 1;

		if (cut(mid) >= m) {
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