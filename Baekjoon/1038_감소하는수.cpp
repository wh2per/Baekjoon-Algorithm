#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;

int n;
vector<long long> arr;

void go(long long idx, int cnt) {
	if (cnt > 10)
		return;
	arr.push_back(idx);
	for (int i = 0; i < 10; ++i) {
		if (idx % 10 > i)
			go(idx * 10 + i, cnt + 1);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n;

	if (n < 10) {
		cout << n;
		return 0;
	}

	for (int i = 0; i < 10; ++i)
		go(i, 1);
	sort(arr.begin(), arr.end());

	long long ans = arr.size() <= n ? -1 : arr[n];
	cout << ans;
	return 0;
}