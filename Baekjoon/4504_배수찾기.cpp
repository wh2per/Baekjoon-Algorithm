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

	int n;
	cin >> n;

	while (1) {
		int num;
		cin >> num;
		if (num == 0)
			break;

		if (num % n != 0)
			cout << num << " is NOT a multiple of " << n << ".\n";
		else
			cout << num << " is a multiple of " << n << ".\n";
	}

	return 0;
}