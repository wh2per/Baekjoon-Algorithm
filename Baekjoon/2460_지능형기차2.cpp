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
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		int x, y;
		cin >> x >> y;

		sum += (y - x);
		if (ans < sum) 
			ans = sum;
	}
	cout << ans;
	return 0;
}