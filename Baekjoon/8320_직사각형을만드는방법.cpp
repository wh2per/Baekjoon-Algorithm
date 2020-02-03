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

	int n, ans = 0;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = i; i * j <= n; ++j)
			++ans;
	}
	cout << ans;

	return 0;
}