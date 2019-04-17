#include <iostream>
using namespace std;

int bj_2292() {
	int n;
	int count = 1;

	cin >> n;
	if (n == 1)
		cout << 1;
	else {
		int temp = 1;
		while (temp < n) {
			temp += 6 * count;
			++count;
		}
		cout << count;
	}
	return 0;
}