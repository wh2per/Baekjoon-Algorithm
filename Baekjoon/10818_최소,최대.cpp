#include <iostream>
#include <climits>
using namespace std;

int bj_10818() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int max = INT_MIN;
	int min = INT_MAX;

	int n;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		if (num > max)
			max = num;
		if (num < min)
			min = num;
	}
	cout << min << " " << max;
	return 0;
}