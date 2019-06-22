#include <iostream>
#include <vector>
using namespace std;

int dn(int n) {
	int value = n;
	while (n != 0) {
		value += n % 10;
		n /= 10;
	}
	
	return value;
}

int bj_4673() {
	vector<bool> self(10037, true);
	for (int i = 1; i <= 10000; ++i) {
		int v = dn(i);
		if (self[v])
			self[v] = false;
	}

	for (int i = 1; i <= 10000; ++i) {
		if (self[i])
			cout << i << '\n';
	}
	return 0;
}