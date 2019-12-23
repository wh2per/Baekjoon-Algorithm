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

	int t;
	int temp;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;

		temp = a;
		for (int j = 0; j < b - 1; j++)
			a = temp * a % 10;

		if (a == 0)
			a = 10;

		cout << a << endl;
	}

	return 0;
}