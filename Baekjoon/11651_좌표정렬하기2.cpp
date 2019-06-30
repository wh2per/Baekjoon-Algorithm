#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp_pos(pair<int, int> &p1, pair<int, int> &p2) {
	if (p1.second < p2.second)
		return true;
	else if (p1.second == p2.second) {
		if (p1.first < p2.first)
			return true;
		else
			return false;
	}
	else
		return false;
}

int bj_11651() {
	vector<pair<int, int>> v;
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end(), cmp_pos);
	for (auto a : v) 
		cout << a.first << " " << a.second << '\n';

 	return 0;
}