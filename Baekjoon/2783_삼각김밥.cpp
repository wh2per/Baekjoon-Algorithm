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

	double ans, x, y;
	int i, n;
	cin >> x >> y >> n;

	ans = x / y * 1000;
	
	for (i = 0; i < n; i++) {
		double xx, yy;
		cin >> xx >> yy;
		
		ans = min(ans, (xx / yy) * 1000);
	}
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << ans << '\n';

	return 0;
}