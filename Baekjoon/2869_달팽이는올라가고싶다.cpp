#include <iostream>
using namespace std;

int bj_2869() {
	int a, b, v;
	cin >> a >> b >> v; 

	int ans = 1;

	if (a >= v)
		cout << ans;
	else {
		int temp = v - a;
		ans += temp / (a - b);
		if (temp % (a - b) != 0)
			++ans;
		cout << ans;
	}
	return 0;
}