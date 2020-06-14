#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	while (1) {
		string n;
		cin >> n;

		if (n == "0")
			break;

		int ans = 2;
		for (auto a : n) {
			if (a == '1')
				ans += 2;
			else if (a == '0')
				ans += 4;
			else
				ans += 3;
		}
		ans += n.length() - 1;
		cout << ans << '\n';
	}

	return 0;
}