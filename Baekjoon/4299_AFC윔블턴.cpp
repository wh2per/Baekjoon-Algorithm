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

	freopen("input.txt", "r", stdin);

	int a, b;
	cin >> a >> b;

	int ans1 = (a + b) / 2;
	int ans2 = (a - b) / 2;;
	if ((a+b)%2!=0 || (a - b) % 2 != 0)
		cout << -1;
	else {
		if (ans1 >= 0 && ans2 >= 0) {
			if (ans1 > ans2)
				cout << ans1 << ' ' << ans2;
			else
				cout << ans2 << ' ' << ans1;
		}
		else
			cout << -1;
	}

	return 0;
}