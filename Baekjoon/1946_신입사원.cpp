#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;

pair<int, int> arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) 
			cin >> arr[i].first >> arr[i].second;
		sort(arr,arr+n);

		int ans = 1;
		int temp = arr[0].second;

		for (int i = 1; i < n; ++i) {
			if (arr[i].second < temp) {
				++ans;
				temp = arr[i].second;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}