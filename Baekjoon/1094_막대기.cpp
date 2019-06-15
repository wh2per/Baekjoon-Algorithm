#include <iostream>
using namespace std;

int bj_1094() {
	int target;
	cin >> target;

	int ans = 0;
	while (target !=0) {
		if (target % 2 == 1)
			++ans;
		target /= 2;
	}
	cout << ans;

	return 0;
}