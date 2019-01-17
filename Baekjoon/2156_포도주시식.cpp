#include <iostream>
#include <algorithm>
using namespace std;

int a[10001];

int bj_2156() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i + 1];
	}

	int d[10001];
	d[1] = a[1];
	d[2] = a[1] + a[2];

	for (int k = 3; k <= n; k++) {
		d[k] = max(d[k - 1], d[k - 2] + a[k]);
		d[k] = max(d[k], d[k - 3] + a[k - 1] + a[k]);
	}

	cout << d[n];
	return 0;
}