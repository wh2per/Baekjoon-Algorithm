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

	int ans = 0;

	int cnt = 5;
	while (cnt--) {
		int n; 
		cin >> n;
		ans += n * n;
	}

	cout << ans % 10;

	return 0;
}