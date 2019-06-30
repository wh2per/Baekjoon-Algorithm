#include <iostream>
#include <vector>
using namespace std;

int bj_2581() {
	int s, e;
	cin >> s >> e;
	vector<bool> check(10001, false);
	check[0] = check[1] = true;

	for (int i = 2; i <= 10000; ++i) {
		if (!check[i]) {
			for (int j = i * i; j <= e; j += i)
				check[j] = true;
		}
	}

	int ans = 0;
	bool flag = false;
	int first = 0;
	for (int i = s; i <= e; ++i) {
		if (!check[i]) {
			ans += i;
			if (!flag) {
				first = i;
				flag = true;
			}
		}
	}

	if (ans == 0)
		cout << -1;
	else {
		cout << ans << '\n';
		cout << first;
	}
	return 0;
}