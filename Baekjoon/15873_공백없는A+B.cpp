#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	string s; 
	cin >> s;
	int ans = 0;

	int size = s.size();

	if (size >= 3) {
		if (size == 4)
			ans = 10 * (s[0] - '0' + s[2] - '0');
		else {
			if (s[1] == '0')
				ans = 10 + s[2] - '0';
			else
				ans = s[0]- '0' + 10;
		}
	}
	else 
		ans = s[0] + s[1] - '0' - '0';

	cout << ans;
	return 0;
}