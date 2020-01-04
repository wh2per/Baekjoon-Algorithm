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
	int n;
	cin >> n;
	while (n--) {
		int sum = 0;
		int ans = INT_MAX;

		int k = 7;
		while (k--) {
			int num;
			cin >> num;
			if (num % 2 == 0){
				sum += num;
				ans = min(ans, num);
			}
		}
		cout << sum << " " << ans << "\n";
	
	return 0;
}