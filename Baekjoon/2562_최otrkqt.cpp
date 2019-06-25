#include <iostream>
using namespace std;

int bj_2562() {
	int a,prev = 0;
	int index, ans;
	for (int i = 1; i < 10; ++i) {
		cin >> a;
		if (a > prev) {
			index = i;
			prev = a;
		}
	}
	cout << prev << endl;
	cout << index;
	return 0;
}