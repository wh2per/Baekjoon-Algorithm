#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int q, w, e, r, t, y;
	cin >> q >> w >> e >> r >> t >> y;

	int d = abs(t - e) + abs(y - r);
	int tempx = abs(t - q);
	int tempy = abs(y - w);
	
	if (d > max(tempx, tempy))
		cout << "bessie";
	else if (d == max(tempx, tempy))
		cout << "tie";
	else
		cout << "daisy";

	return 0;
}