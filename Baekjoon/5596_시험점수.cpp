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

	//freopen("input.txt", "r", stdin);

	int q, w, e, r, a, s, d, f;
	cin >> q >> w >> e >> r >> a >> s >> d >> f;

	cout << max(q + w + e + r, a + s + d + f);

	return 0;
}