#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int bj_1152() {
	string x;
	getline(cin, x);
	int ans = 1;

	for (int i = 0; i < x.length(); i++) {
		if (x.at(i) == ' ')
			ans++;
	}
	if (x.at(0) == ' ')
		ans--;
	if (x.at(x.length() - 1) == ' ')
		ans--;

	cout << ans;

	return 0;
}