#include <iostream>
#include <vector>
using namespace std;

int bj_1904() {
	int n;
	cin >> n;

	vector<long long> d(n + 1, 0);

	d[0] = 1;
	d[1] = 1;

	for (int i = 2; i < n + 1; ++i)
		d[i] = (d[i - 1] + d[i - 2]) % 15746;

	cout << d[n];
	return 0;
}