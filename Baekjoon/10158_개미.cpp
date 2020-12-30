#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int w, h, p, q, t, temp;
	cin >> w >> h >> p >> q >> t;

	p += t; q += t;
	p %= (2 * w); q %= (2 * h);

	if (p > w)
		p = 2 * w - p;
	if (q > h)
		q = 2 * h - q;

	cout << p << " " << q;

	return 0;
}