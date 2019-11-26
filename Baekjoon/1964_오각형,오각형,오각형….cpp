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

	long long a, b;
	cin >> a;

	b = 1 + 4 * a + 3 * a * (a - 1) / 2;
	b %= 45678;

	cout << b << endl;

	return 0;
}