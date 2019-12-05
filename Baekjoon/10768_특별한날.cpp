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

	if (a > 2) {
		cout << "After";
	}
	else if (a == 2) {
		if (b == 18) {
			cout << "Special";
		}
		else if (b < 18) {
			cout << "Before";
		}
		else {
			cout << "After";
		}
	}
	else {
		cout << "Before";
	}

	return 0;
}