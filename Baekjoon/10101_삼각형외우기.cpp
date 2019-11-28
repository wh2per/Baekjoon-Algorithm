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

	int q, w, e;
	cin >> q >> w >> e;

	if (q==w && w==e && e==60)
		cout << "Equilateral";
	else if (q + w + e == 180) {
		if (q == w || w == e || q == e)
			cout << "Isosceles";
		else
			cout << "Scalene";
	}
	else {
		cout << "Error";
	}
		
	return 0;
}