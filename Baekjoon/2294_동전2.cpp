#include <iostream>
#include <vector>
using namespace std;

int bj_2294() {
	int n, k;
	cin >> n >> k;
	vector<int> coin(n);
	vector<int> d(k + 1, -1);

	for (int i = 0; i < n; ++i)
		cin >> coin[i];
	d[0] = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (j - coin[i] >= 0 && d[j - coin[i]] != -1) {
				if (d[j] == -1 || d[j] > d[j - coin[i]] + 1)
					d[j] = d[j - coin[i]] + 1;
			}
		}
	}
	cout << d[k];
	return 0;
}