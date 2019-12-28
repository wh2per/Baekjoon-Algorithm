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

	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;

		if (a > b)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}