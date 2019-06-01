#include <iostream>
#include <algorithm>
using namespace std;

int bj_2609() {
	int a, b;
	cin >> a >> b;

	int f = max(a, b);
	int s = min(a, b);

	while (s != 0) {
		int r = f % s;
		f = s;
		s = r;
	}

	cout << f<<'\n';
	cout << a * b / f;

	return 0;
}