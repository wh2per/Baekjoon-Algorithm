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

	int n, a = 3, b = 6, ans = 0;

	cin >> n;

	while(n--){
		ans += a;
		a = a + b;
		b += 3;
	}

	cout << ans;

	return 0;
}