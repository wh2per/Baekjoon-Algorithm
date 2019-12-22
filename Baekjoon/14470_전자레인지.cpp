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

	int a, b, c, d, e;
	cin >> a >>b >> c >> d >> e;

	if (a < 0) 
		cout << -1 * a * c + d + e * b;
	else if (a > 0)
		cout << e * (b - a);
	else
		cout << d + e * b;
	return 0;
}