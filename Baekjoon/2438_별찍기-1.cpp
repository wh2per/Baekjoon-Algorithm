#include <iostream>
using namespace std;

int bj_2438() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i <= j; ++i)
			cout << "*";
		cout << '\n';
	}
	return 0;
}