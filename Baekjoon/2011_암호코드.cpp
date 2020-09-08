#include <iostream>
#include <string>
using namespace std;

int arr[5001];
int dp[5001];

int main() {
	string s;
	cin >> s;
	for (int i = 1; i <= s.length(); ++i)
		arr[i] = s[i - 1] - '0';

	if (s.length() == 1 && s[0] == '0') {
		cout << 0;
		return 0;
	}

	dp[0] = 1;
	for (int i = 1; i <= s.length(); ++i) {
		if (arr[i] >= 1 && arr[i] <= 9) {
			dp[i] = (dp[i - 1] + dp[i]) % 1000000;
		}
		if (i == 1)
			continue;

		int temp = arr[i] + arr[i - 1] * 10;
		if (temp >= 10 && temp <= 26) {
			dp[i] = (dp[i - 2] + dp[i]) % 1000000;
		}
	}

	cout << dp[s.length()];

	return 0;
}