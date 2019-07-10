#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bj_1965() {
	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> d(n);

	for (int i = 0; i < n; i++) 
		cin >> v[i];

	for (int i = 0; i < n; ++i) {
		d[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (v[j] < v[i] && d[j] + 1 > d[i])
				d[i] = d[j] + 1;
		}
	}

	cout << *max_element(d.begin(), d.end()) << '\n';
	return 0;
}