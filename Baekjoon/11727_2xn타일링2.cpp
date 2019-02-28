#include <iostream>
using namespace std;

int bj_11727() {
	int d[1001];
	int n;
	cin >> n;

	d[0] = 1;
	d[1] = 1;

	if (n > 1) {
		for (int i = 2; i <= n; i++) {
			d[i] = (2 * d[i - 2] + d[i - 1]) % 10007;
		}

		cout << d[n];
	}
	else
		cout << 1;
	return 0;
}