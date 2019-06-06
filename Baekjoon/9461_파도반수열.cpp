#include <iostream>
#include <vector>
using namespace std;

int bj_9461() {
	int t; cin >> t;
	vector<long long> d(101);
	d[1] = 1;
	d[2] = 1;
	d[3] = 1;
	d[4] = 2;
	d[5] = 2;
	for (int i = 6; i < 101; ++i)
		d[i] = d[i - 1] + d[i - 5];
	for (int i = 0; i < t; ++i) {
		int num; cin >> num;
		cout << d[num] << "\n";
	}
	return 0;
}