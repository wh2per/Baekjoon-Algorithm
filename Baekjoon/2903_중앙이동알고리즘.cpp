#include <iostream>
using namespace std;

int bj_2903() {
	int n;
	cin >> n;
	int ans = 2;
	for (int i = 0; i < n; ++i)
		ans = 2 * ans - 1;
	cout << ans * ans;
	return 0;
}