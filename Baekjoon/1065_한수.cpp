#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int bj_1065(){
	int n;
	int ans;
	cin >> n;

	if (n < 100) {
		ans = n;
	}
	else {
		ans = 99;

		for (int i = 100; i <= n; i++) {
			int arr[3];
			arr[0] = i / 100;
			arr[1] = (i - (100 * arr[0])) / 10;
			arr[2] = i % 10;

			if ((arr[1] - arr[0]) == (arr[2] - arr[1]))
				ans++;
		}
	}

	cout << ans;

	return 0;
}