#include <iostream>
#include <vector>
using namespace std;

int bj_1011() {
	vector<long long> d(46342,0);
	d[0] = 1;
	d[1] = 1;
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int x, y;
		cin >> x >> y;
		int diff = y - x;

		long long k = 1;
		while (1) {
			if (d[k] == 0) {
				d[k] = k * k;
			}
			if (d[k] >= diff)
				break;
			++k;
		}

		if (diff > ((k*k) + ((k - 1)*(k - 1))) / 2)
			cout << k * 2 - 1 << '\n';
		else
			cout << k * 2 - 2 << '\n';
	}
	return 0;
}