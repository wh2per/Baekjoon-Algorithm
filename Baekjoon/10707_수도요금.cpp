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

	int a, b, c, d, p;
	cin >> a >> b >> c >> d >> p;
	int asum = 0, bsum = b;

	asum = p * a;
	if (p - c > 0) 
		bsum += d * (p - c);
	cout << min(asum, bsum);
	return 0;
}