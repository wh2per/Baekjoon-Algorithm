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

	int n, m, k;
	cin >> n >> m >> k;

	int ans = 0;
	while (n >= 2 && m >= 1 && n + m >= k + 3) {
		n -= 2;
		--m;
		++ans;
	}

	cout << ans;

	return 0;
}