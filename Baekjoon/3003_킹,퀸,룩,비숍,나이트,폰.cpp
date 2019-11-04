#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int k, q, l, b, n, p;
	cin >> k >> q >> l >> b >> n >> p;

	cout << 1 - k << " " << 1 - q << " " << 2 - l << " " << 2 - b << " " << 2 - n << " " << 8 - p;

	return 0;
}