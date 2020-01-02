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

	int ans = 0;
	int count;
	cin >> count;
	while (count--) {
		int a, b, c;
		cin >> a >> b >> c;

		int sum = 0; 

		if (a == b && b == c)
			sum = 10000 + a * 1000;
		else if (a != b && b != c && c != a)
			sum = max(max(a, b), c) * 100;
		else {
			if (a == b)
				sum = 1000 + a * 100;
			else if (b == c)
				sum = 1000 + b * 100;
			else
				sum = 1000 + c * 100;
		}
		
		ans = max(ans, sum);
	}

	cout << ans;
	return 0;
}