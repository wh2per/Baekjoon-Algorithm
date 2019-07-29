#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int bj_2697() {
	int t;
	cin >> t;
	while (t--) {
		string n;
		cin >> n;

		vector<int> v;
		for (auto a : n)
			v.push_back(a - '0');

		int count = -1;
		do {
			count++;
			if (count > 0)
				break;
		} while (next_permutation(v.begin(), v.end()));

		if (count == 0)
			cout << "BIGGEST";
		else {
			for (auto a : v)
				cout << a;
		}
		cout << "\n";
	}
	return 0;
}