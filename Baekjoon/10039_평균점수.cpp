#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int sum = 0;
	int t = 5;
	while (t--) {
		int num;
		cin >> num;

		if (num < 40)
			num = 40;

		sum += num;
	}
	cout << sum / 5;
	return 0;
}