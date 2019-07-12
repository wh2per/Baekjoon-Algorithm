#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bj_11054() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) 
		cin >> a[i];
	vector<int> d1(n);		// 증가부분수열
	vector<int> d2(n);		// 감소부분수열
	
	for (int i = 0; i < n; i++) {
		d1[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d1[j] + 1 > d1[i])
				d1[i] = d1[j] + 1;
		}
	}

	for (int i = n-1; i >= 0; --i) {
		d2[i] = 1;
		for (int j = n-1; j > i; --j) {
			if (a[j] < a[i] && d2[j] + 1 > d2[i])
				d2[i] = d2[j] + 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (ans < d1[i] + d2[i])
			ans = d1[i] + d2[i];
	}
	cout << ans-1 << endl;

	return 0;
}
