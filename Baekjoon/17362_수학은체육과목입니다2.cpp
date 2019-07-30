#include <iostream>
using namespace std;

int bj_17362() {
	int n;
	cin >> n;

	int ret = n % 8;
	if (ret == 1)
		cout << 1;
	else if (ret == 5)
		cout << 5;
	else if (ret == 2 || ret == 0)
		cout << 2;
	else if (ret == 3 || ret == 7)
		cout << 3;
	else
		cout << 4;
	return 0;
}