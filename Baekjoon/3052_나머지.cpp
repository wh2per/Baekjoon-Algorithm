#include <iostream>
#include <set>
using namespace std;

int bj_3052() {
	int t = 10;
	set<int> s;
	while (t--) {
		int a;
		cin >> a;
		s.insert(a % 42);
	}
	cout << s.size();
	return 0;
}