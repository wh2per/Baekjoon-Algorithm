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

	int ans = 0;
	while (n--) {
		int a, b;
		cin >> a >> b;
		ans += b % a;
	}

	cout << ans;

	return 0;
}