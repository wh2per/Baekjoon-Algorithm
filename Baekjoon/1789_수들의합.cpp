#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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
	long long max = 0;
	cin >> max;

	int n = 1;

	int ans = 0;
	long long sum = 0;

	while (1) {
		sum += n;
		++ans;

		if (sum > max) {
			--ans;
			break;
		}
		++n;
	}
	cout << ans;
	return 0;
}