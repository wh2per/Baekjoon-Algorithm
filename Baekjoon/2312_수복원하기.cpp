#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int bj_2312() {
	vector<bool> check(100002, false);
	int temp = 100001;
	check[0] = check[1] = true;
	for (int i = 2; i*i <= temp; ++i) {
		if (!check[i]) {
			for (int j = i * i; j <= temp; j += i)
				check[j] = true;
		}
	}
	
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int num;
		cin >> num;
		int ans = 1;

		for (int j = 2; j <= temp; ++j) {
			if (!check[j]) {
				int count = 0;
				int t = num;
				while (t%j == 0) {
					++count;
					t /= j;
				}
				if(count!=0)
					cout << j << " " << count << '\n';
				ans *= pow(j, count);
			}
			if (ans == num)
				break;
		}
	}

	return 0;
}