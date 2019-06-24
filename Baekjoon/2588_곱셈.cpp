#include <iostream>
using namespace std;

int bj_2588() {
	int a, b, temp;
	cin >> a >> b;
	int ans = a * b;
	
	for (int i = 0; i < 3; ++i) {
		int temp = b % 10;
		cout << a * temp << '\n';
		b /= 10;
	}
	cout << ans;
	
	return 0;
}