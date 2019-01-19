#include <iostream>
#include <algorithm>
using namespace std;

int bj_2579() {
	int n;
	cin >> n;
	int a[301];
	int d[301][2];

	for (int i = 0; i < n; i++)
		cin >> a[i + 1];

	d[1][1] = a[1];

	for (int i = 2; i <= n; i++) {
		d[i][2] = d[i - 1][1] + a[i];
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + a[i];
	}

	cout << max(d[n][1], d[n][2]);

	return 0;
}