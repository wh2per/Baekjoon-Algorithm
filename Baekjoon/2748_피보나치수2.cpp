#include <iostream>
#include <vector>
using namespace std;

int bj_2748() {
	int n;
	cin >> n;
	vector<long long> v(n + 1, 0);
	v[0] = 0;
	v[1] = 1;

	for (int i = 2; i <= n; ++i)
		v[i] = v[i - 1] + v[i - 2];
	cout << v[n];
	return 0;
}