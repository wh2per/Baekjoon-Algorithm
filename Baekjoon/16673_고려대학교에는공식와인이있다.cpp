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


	int c,k,p;
	cin >> c >> k >> p;

	int ans = 0;
	for (int i = 1; i <= c; ++i)
		ans += k * i + p * i * i;
	cout << ans;

	return 0;
}