#include <iostream>
#include <algorithm>
using namespace std;

int p[1001];
int d[1001];
int bj_11052() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> p[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			d[i] = max(d[i], d[i - j] + p[j]);
	}

	cout << d[n] << '\n';
	return 0;
}