#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int a;
	double b, c;
	cin >> a >> b >> c;

	double d = sqrt(b * b + c * c);

	while (a--) {
		double n;
		cin >> n;

		if (n <= d)
			cout << "DA\n";
		else
			cout << "NE\n";
	}

	return 0;
}