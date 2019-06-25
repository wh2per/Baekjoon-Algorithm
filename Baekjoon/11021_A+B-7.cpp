#include <iostream>
using namespace std;

int bj_11021() {
	int t;
	cin >> t;

	for (int i = 1; i <= t; ++i) {
		int a, b;
		cin >> a >> b;
		cout << "Case #" << i << ": " << a + b<<endl;
	}
	return 0;
}