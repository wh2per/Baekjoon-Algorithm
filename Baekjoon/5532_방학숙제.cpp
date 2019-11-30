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

	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;

	if (a % c == 0)
		a /= c;
	else {
		a /= c;
		++a;
	}
	
	if (b % d == 0)
		b /= d;
	else {
		b /= d;
		++b;
	}

	cout << l - max(a, b);

	return 0;
}