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

	//freopen("input.txt", "r", stdin);

	int n, f;
	cin >> n >> f;

	n = (n / 100) * 100;

	int i,ans = 0;
	for (i = 0; i < 100; ++i) {
		ans = n;
		if ((ans += i) % f == 0)
			break;
	}

	if (i < 10)
		cout << "0";
	cout << i;

	return 0;
}