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
	cin >> t;

	int ans = 0;

	for (int i = 1; i <= t; ++i) {
		int n;
		cin >> n;

		cout << (n * i - ans) << " ";
		ans += (n * i - ans);
	}

	return 0;
}