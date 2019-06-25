#include <iostream>
#include <vector>
using namespace std;

int bj_2577() {
	vector < int> v(10, 0);

	int a, b, c, ans;
	cin >> a >> b >> c;
	ans = a * b * c;

	while (ans != 0) {
		int idx = ans % 10;
		++v[idx];
		ans /= 10;
	}

	for (auto a : v)
		cout << a << endl;
	return 0;
}