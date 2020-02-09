#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	while (1) {
		string s;
		cin >> s;

		if (s == "0")
			break;

		int ans = 0;
		if (s.length() == 1)
			cout << s << endl;
		else {
			while (s.length() != 1) {
				ans = 0;
				for (auto a : s)
					ans += a - '0';
				s = to_string(ans);
			}
			cout << ans << endl;
		}
	}

	return 0;
}