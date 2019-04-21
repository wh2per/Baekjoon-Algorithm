#include <iostream>
#include <list>
using namespace std;

int bj_2164() {
	list<int> l;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		l.push_back(i + 1);

	while (l.size() > 1) {
		l.pop_front();
		int t = *l.begin();
		l.pop_front();
		l.push_back(t);
	}

	cout << *l.begin();
	return 0;
}