#include <iostream>
#include <vector>
using namespace std;

int bj_4948() {
	vector<bool> check(123456 * 2 + 1, false);
	int temp = 123456 * 2;
	int pn = 0;
	for (int i = 2; i*i <= temp; ++i) {
		if (!check[i]) {
			for (int j = i * i; j <= temp; j += i)
				check[j] = true;
		}
	}
	while (1) {
		int n=-1;
		cin >> n;
		if (n == 0)
			break;
		int count = 0;
		for (int i = n+1; i <= 2 * n; ++i) {
			if (!check[i])
				++count;
		}
		cout << count << '\n';
	}
	return 0;
}