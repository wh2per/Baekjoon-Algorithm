#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int c;
		cin >> c;

		int ans = 0;
		double sum = 0;
		while (c--) {
			int num;
			float score;

			cin >> num >> score;
			ans += num;
			sum += num * score;
		}
		printf("%d %.1f\n", ans, round(10 * sum / ans) / 10);
	}

	return 0;
}