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

	int a, b;
	cin >> a >> b;

  	for (int i = 1; i <= a; ++i) {
		if (a % i == 0)
			--b;
		if (b == 0) {
			cout << i;
			return 0;
		}
	}
	cout << 0;

	return 0;
}