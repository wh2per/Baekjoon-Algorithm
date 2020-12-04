#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int low = 0, high = 0;
	int sum = arr[0];
	int result = INT_MAX;

	while (low <= high && high < n) {
		if (sum < s)
			sum += arr[++high];
		else if (sum == s) {
			result = min(result, high - low + 1);
			sum += arr[++high];
		}
		else if (sum > s) {
			result = min(result, high - low + 1);
			sum -= arr[low++];
		}
	}

	if (result == INT_MAX)
		cout << 0;
	else
		cout << result;

	return 0;
}