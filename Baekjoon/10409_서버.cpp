#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
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
	vector<int> arr(50, 0);
	int n, t,sum=0,cnt=0;
	cin >> n >> t;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < n; ++i) {
		if (sum + arr[i] > t)
			break;
		sum += arr[i];
		++cnt;
	}

	cout << cnt;


	return 0;
}