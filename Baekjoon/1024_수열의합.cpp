#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int n, l;
	cin >> n >> l;

	int x = -1;
	int idx = -1;

	for (int i = l; i <= 100; ++i) {
		int t = (i - 1) * i / 2;
		if ((n - t) % i == 0 && (n - t)/i >= 0) {
			x = (n - t) / i;
			idx = i;
			break;
		}
	}
	
	if (x == -1)
		cout << -1;
	else {
		for (int i = 0; i < idx; ++i)
			cout << x+i << " ";
	}

	return 0;
}