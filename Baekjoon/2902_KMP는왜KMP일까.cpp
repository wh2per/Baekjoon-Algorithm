#include <iostream>
#include <string>
#include <vector>
using namespace std;

int bj_2902() {
	string s;
	string ans = "";
	cin >> s;

	for (char c : s) {
		if (isupper(c))
			ans += c;
	}
	cout << ans;
	return 0;
}