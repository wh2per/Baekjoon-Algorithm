#include <iostream>
using namespace std;
bool broken[10];
int possible(int c) {
	if (c == 0) {
		if (broken[0])
			return 0;
		else
			return 1;
	}
	int len = 0;
	while (c > 0) {
		if (broken[c % 10])
			return 0;
		len += 1;
		c /= 10;
	}
	return len;
}
int bj_1107() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		broken[x] = true;
	}
	int ans = abs(n - 100);		// +,- 로 가는 횟수 


	for (int i = 0; i <= 1000000; i++) {
		int c = i;
		int len = possible(c);
		if (len > 0) {
			int press = abs(c - n);
			if (ans > len + press)
				ans = len + press;
		}
	}
	cout << ans;
	return 0;
}