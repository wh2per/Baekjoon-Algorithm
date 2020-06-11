#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	int cnt = 0;
	while (1) {
		if (a > b) {
			cout << -1 << '\n';
			break;
		}
		if (a == b) {
			cout << cnt + 1 << '\n';
			break;
		}

		if (b % 10 == 1) {
			b /= 10;
		}
		else if (b % 2 == 0) {
			b /= 2;
		}
		else {
			cout << -1 << '\n';
			break;
		}
		cnt++;
	}
	return 0;
}