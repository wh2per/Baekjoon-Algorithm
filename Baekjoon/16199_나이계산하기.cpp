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

	int q1, q2, q3, a1, a2, a3;
	cin >> q1 >> q2 >> q3 >> a1 >> a2 >> a3;

	int diff = 0;
	if (a1 - q1 == 0)
		diff = 0;
	else if (a1 - q1 == 1) {
		if (a2 == q2) {
			if (a3 >= q3)
				diff = 1;
		}
		else if (a2 > q2)
			diff = 1;
	}
	else {
		if (a2 == q2) {
			if (a3 >= q3)
				diff = 2;
			else
				diff = 1;
		}
		else if (a2 > q2)
			diff = 2;
		else
			diff = 1;
	}

	if (a1 - q1 < 2)
		cout << diff << "\n" << a1 - q1 + 1 << "\n" << a1 - q1;
	else
		cout << a1 - q1 + diff - 2 << "\n" << a1 - q1 + 1 << "\n" << a1 - q1;

	return 0;
}