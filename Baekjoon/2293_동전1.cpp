#include <iostream>
#include <vector>
using namespace std;

int bj_2293() {
	int n, k;
	cin >> n >> k;
	vector<int> coin(n);
	vector<int> d(k + 1, 0);

	for (int i = 0; i < n; ++i)
		cin >> coin[i];
	d[0] = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (j - coin[i] >= 0)
				d[j] += d[j - coin[i]];
		}
	}
	cout << d[k];
	return 0;
}