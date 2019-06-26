#include <iostream>
#include <string>
using namespace std;

int bj_8958() {
	int t; cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int ans = 0;
		int acc = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == 'O') {
				++acc;
				ans += acc;
			}
			else 
				acc = 0;
		}
		cout << ans << '\n';
	}
	return 0;
}