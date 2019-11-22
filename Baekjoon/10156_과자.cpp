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

	int k, n, m;
	cin >> k >> n >> m;

	int sum = k * n;
	if (sum - m <= 0)
		cout << 0;
	else
		cout << sum - m;

	return 0;
}