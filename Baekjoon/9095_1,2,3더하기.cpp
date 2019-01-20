#include <iostream>
using namespace std;

int bj_9095() {
	int n;
	int d[11];

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		d[1] = 1;
		d[2] = 2;
		d[3] = 4;

		if (num > 3) {
			for (int i = 4; i <= num; i++)
				d[i] = d[i - 2] + d[i - 1] + d[i - 3];
		}
		cout << d[num] << '\n';
	}
	return 0;
}