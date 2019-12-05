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

	int q, w, e, r, t, y;
	cin >> q >> w >> e >> r >> t >> y;

	cout << q + w + e + r + t + y - min(min(q, w), min(e, r)) - min(t, y);

	return 0;
}