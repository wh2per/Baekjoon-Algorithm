#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct cmp_pos {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		if (p1.first > p2.first) {
			return false;
		}
		else if (p1.first < p2.first) {
			return true;
		}
		else {
			if (p1.second > p2.second) {
				return false;
			}
			else
				return true;
		}
	}
};

int bj_11650() {
	int n;
	cin >> n;
	vector<pair<int, int>> m;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		m.push_back(make_pair(x, y));
	}

	sort(m.begin(), m.end(), cmp_pos());
	for (auto a : m)
		cout << a.first << " " << a.second << '\n';

	return 0;
}