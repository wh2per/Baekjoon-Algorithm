#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int guitar_end;
int guitar_max;

set<int> guitar(set<int> &list, vector<int> &a, int i) {
	set<int> s;
	if (i == guitar_end)
		return list;

	for (auto li : list) {
		if (li + a[i] <= guitar_max)
			s.insert(li + a[i]);
		if (li - a[i] >= 0)
			s.insert(li - a[i]);
	}
	s = guitar(s, a, i + 1);
	return s;
}

int bj_1495() {
	int n, s, m;
	cin >> n >> s >> m;
	guitar_end = n;
	guitar_max = m;
	vector<int> a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	set<int> list;
	if (s + a[0] <= m)
		list.insert(s + a[0]);
	if (s - a[0] >= 0)
		list.insert(s - a[0]);
	list = guitar(list, a, 1);

	if (list.size() == 0)
		cout << -1;
	else
		cout << *max_element(list.begin(), list.end());	
	return 0;
}