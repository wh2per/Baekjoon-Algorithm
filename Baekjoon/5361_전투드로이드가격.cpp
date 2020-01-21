#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	while (n--) {
		double q, w, e, r, t;
		cin >> q >> w >> e >> r >> t;

		printf("$%.2lf\n", q * 350.34 + w * 230.90 + e * 190.55 + r * 125.30 + t * 180.90);
	}

	return 0;
}