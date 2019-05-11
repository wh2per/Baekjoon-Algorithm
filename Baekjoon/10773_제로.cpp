#include <iostream>
#include <vector>
using namespace std;

int bj_10773() {
	vector<int> v;
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int num;
		cin >> num;
		if (num != 0)
			v.push_back(num);
		else
			v.pop_back();
	}

	int ans = 0;
	for (auto a : v)
		ans += a;
	cout << ans;
	return 0;
}