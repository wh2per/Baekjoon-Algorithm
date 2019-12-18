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

	int a, b;
	cin >> a >> b;

	if (a > 0) {
		if (b > 0)
			cout << 1;
		else
			cout << 4;
	}
	else {
		if (b > 0)
			cout << 2;
		else
			cout << 3;
	}


	return 0;
}