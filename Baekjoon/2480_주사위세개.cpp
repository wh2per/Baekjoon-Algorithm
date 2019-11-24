#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int a, b, c;
	cin >> a >> b >> c;

	int m = max(a, max(b, c));
	if (a == b || a == c || b == c) {
		if (a == b && b == c) {
			cout << 10000 + a * 1000;
		}
		else {
			if (a == b || a == c)
				cout << 1000 + a * 100;
			else if (b == c)
				cout << 1000 + c * 100;
		}
	}
	else {
		cout << 100 * m;
	}
	return 0;
}