#include <iostream>
using namespace std;

int a[33];
int b[33];

int main() {
	a[1] = 1;
	b[2] = 1;
	int d, k;

	for (int i = 3; i <= 30; ++i) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}
	cin >> d >> k;

	int ans1 = a[d];
	int ans2 = b[d];

	for (int i = 1; i <= 100000; ++i) {
		if ((k - ans1 * i) % ans2 == 0) {
			cout << i << "\n" << (k - ans1 * i) / ans2;
			return 0;
		}
	}
	return 0;
}