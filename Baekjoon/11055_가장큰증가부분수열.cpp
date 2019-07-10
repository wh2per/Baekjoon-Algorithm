#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bj_11055() {
	int n;
	cin >> n;
	 
	vector<int> v(n);
	vector<int> d(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int ans = -1;
	for (int i = 0; i < n; ++i) {
		int temp = 0;
		for (int j = 0; j < i; ++j) {
			if (v[j] < v[i] && temp < d[j])
				temp = d[j];
		}
		d[i] = temp + v[i];
		if (ans < d[i])
			ans = d[i];
	}

	cout << ans;
	return 0;
}