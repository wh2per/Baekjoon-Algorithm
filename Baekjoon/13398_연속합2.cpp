#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bj_13398() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	vector<int> d1(n);
	vector<int> d2(n);

	for (int i = 0; i < n; i++) {
		d1[i] = a[i];
		if (i == 0) continue;
		d1[i] = max(d1[i], d1[i - 1] + a[i]);
	}

	for (int i = n-1; i >= 0; --i) {
		d2[i] = a[i];
		if (i == n-1) continue;
		d2[i] = max(d2[i], d2[i + 1] + a[i]);
	}

	int ans = *max_element(d1.begin(), d1.end());

	for (int i = 1; i < n - 1; i++) {
		if (ans < d1[i - 1] + d2[i + 1]) {
			ans = d1[i - 1] + d2[i + 1];
		}
	}
	cout << ans << '\n';
	return 0;
}