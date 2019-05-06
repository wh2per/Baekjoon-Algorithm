#include <iostream>
#include <vector>
using namespace std;

int bj_9020() {
	vector<bool> check(20001, false);
	int temp = 20000;
	int pn = 0;
	for (int i = 2; i*i <= temp; ++i) {
		if (!check[i]) {
			for (int j = i * i; j <= temp; j += i)
				check[j] = true;
		}
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int num = -1;
		cin >> num;
		for (int j = num/2; j>0; --j) {
			if (!check[j] && !check[num - j]) {
				cout << j << " " << num-j << '\n';
				break;
			}
		}
	}
	
	return 0;
}