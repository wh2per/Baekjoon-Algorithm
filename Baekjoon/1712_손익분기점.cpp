#include <iostream>
using namespace std;

int bj_1712() {
	int a, b, c;
	cin >> a >> b >> c;

	if (b >= c)
		cout << -1;
	else {
		int ans = a / (c - b);
		cout << ++ans;
	}
	
	return 0;
}