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

	int q, w, e, r, t, y;
	cin >> q >> w >> e >> r >> t >> y;

	if (q * 3 + w * 2 + e < r * 3 + t * 2 + y)
		cout << "B";
	else if (q * 3 + w * 2 + e == r * 3 + t * 2 + y)
		cout << "T";
	else
		cout << "A";

	return 0;
}