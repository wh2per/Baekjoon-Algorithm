#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool electric_cmp(pair<int, int> &p1, pair<int, int> &p2) {
	if (p1.first > p2.first)
		return false;
	else
		return true;
}

int bj_2565() {
	int n;
	cin >> n;

	vector<pair<int, int>> a;
	vector<int> d(n);

	for (int i = 0; i < n; ++i) {
		int n1, n2;
		cin >> n1;
		cin >> n2;
		a.push_back({ n1, n2 });
	}
	sort(a.begin(), a.end(), electric_cmp);
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j].second < a[i].second && d[j] + 1 > d[i]) 
				d[i] = d[j] + 1;
		}
	}

	cout << n - *max_element(d.begin(), d.end());

	return 0;
}